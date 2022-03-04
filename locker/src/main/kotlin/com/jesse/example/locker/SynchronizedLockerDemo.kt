package com.jesse.example.locker

import java.util.concurrent.ConcurrentHashMap
import kotlin.concurrent.thread

class SynchronizedLockerDemo {
    companion object {
        val lockers = ConcurrentHashMap<Int, Any> ()
    }

    fun runById(id:Int, callback:()->Unit) {
        val lock = lockers.computeIfAbsent(id){
            Any()
        }
        synchronized(lock) {
            Thread.sleep(1000)
            println(id)
            callback()
            Thread.sleep(1000)
        }
    }
}

fun main() {
    val runner = SynchronizedLockerDemo()
    repeat(4){ x->
        repeat(3){ y->
            thread {
                Thread.currentThread().name = "thread-$x-$y"
                runner.runById(x){
                    println(Thread.currentThread().name)
                }
            }
        }
    }
}