package com.jesse.example.nio.socket

import java.net.InetSocketAddress
import java.nio.channels.SelectionKey
import java.nio.channels.Selector
import java.nio.channels.ServerSocketChannel

class NoBlockSocketPractice {

    companion object {
        const val PORT=12307
        val selector:Selector = Selector.open()
    }

    fun initServer(){
        ServerSocketChannel.open().also { serverSocketChannel ->
            serverSocketChannel.configureBlocking(false)
            serverSocketChannel.bind(InetSocketAddress(PORT))
            serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT)
        }
    }
}

fun main() {
    NoBlockSocketPractice().also { noBlockSocketPractice ->
        noBlockSocketPractice.initServer()
        println("server started")
    }
}