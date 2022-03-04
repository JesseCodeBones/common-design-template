package com.jesse.example.locker

import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.TimeUnit
import java.util.concurrent.locks.ReentrantLock
import kotlin.concurrent.thread


class LockerLockDemo {
    companion object {
        val lockers = ConcurrentHashMap<Int, ReentrantLock> ()
    }

    fun concurrentRun(index:Int, callback:()->Unit) {
        val locker = lockers.computeIfAbsent(index) {
            ReentrantLock()
        }
        try {
            try {
                if (!locker.tryLock(5, TimeUnit.SECONDS)) {//max run time for all pending thread
                    throw IllegalStateException("timeout to retrieve lock ${Thread.currentThread().name}")
                }
            }catch (e:InterruptedException) {
                Thread.currentThread().interrupt()
                throw IllegalStateException("Read lock retrieving failed.", e)
            }

            Thread.sleep(1000)
            println(index)
            callback.apply {  }
            Thread.sleep(1000)

        }finally {
            locker.unlock()
        }
    }
}

fun main() {
    val runner = LockerLockDemo()
    repeat(4){ x->
        repeat(3){ y->
            thread {
                Thread.currentThread().name = "thread-$x-$y"
                runner.concurrentRun(x){
                    println(Thread.currentThread().name)
                }
            }
        }
    }
}