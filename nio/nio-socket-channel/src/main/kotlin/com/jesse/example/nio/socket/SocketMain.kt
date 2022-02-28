package com.jesse.example.nio.socket

import java.net.InetSocketAddress
import java.nio.ByteBuffer
import java.nio.CharBuffer
import java.nio.channels.FileChannel
import java.nio.channels.ServerSocketChannel
import java.nio.channels.SocketChannel
import java.nio.charset.Charset
import java.nio.file.Paths
import java.nio.file.StandardOpenOption
import java.util.*
import kotlin.concurrent.thread

class SocketMain {
    companion object {
        const val PORT = 12306
    }

    fun createServer() {
        ServerSocketChannel.open().also { serverSocketChannel ->
            val socketServer = serverSocketChannel.socket().bind(InetSocketAddress(PORT))
            while (true){
                val client = serverSocketChannel.accept()
                println("Connection Set:  " + client.remoteAddress);
                val filePath = Paths.get("C:\\TEMP\\test.txt")
                FileChannel.open(
                    filePath, EnumSet.of(
                        StandardOpenOption.APPEND
                    )
                ).also { fileChannel ->
                    val buffer: ByteBuffer = ByteBuffer.allocate(1024)
                    while (client.read(buffer) > 0) {
                        buffer.flip()
                        fileChannel.write(buffer)
                        buffer.clear()
                    }
                    fileChannel.close()
                    println("finished the write")
                }
            }
        }
    }


    fun mockSendText() {
        SocketChannel.open().also { socketChannel ->
            socketChannel.connect(InetSocketAddress(PORT))
            val strToWrite = "hello world ${Thread.currentThread().name} \n"
            val c = CharBuffer.wrap(strToWrite)
            val byteBuffer = Charset.forName("ISO-8859-1").encode(c)
            socketChannel.write(byteBuffer)
            socketChannel.close()
        }
    }


}

fun main() {
    SocketMain().also { socketMain->
        thread {
            socketMain.createServer()
        }
        Thread.sleep(2000)
        repeat(1000){
            thread {
                socketMain.mockSendText()
            }
        }
    }
}