
import java.nio.file.Files
import java.nio.file.Paths
import java.nio.file.StandardOpenOption
import java.time.LocalDateTime
import kotlin.concurrent.thread


class FileNIOTestMain {

    companion object {

    }

    fun writeAndRead(){
        val userDir = System.getProperty("user.dir")
        val strToWrite = "hello world"
        Files.write(Paths.get("$userDir/build/test.text"),
            strToWrite.byteInputStream(Charsets.UTF_8).readAllBytes(),
        StandardOpenOption.APPEND)

        repeat(300){
            thread {
                val result = Files.readString(Paths.get("$userDir/build/test.text"))
                if (it == 299) {
                    println(LocalDateTime.now())
                }
                println(it)
            }
        }

    }
}

fun main() {
    println(LocalDateTime.now())
    FileNIOTestMain().writeAndRead()

}