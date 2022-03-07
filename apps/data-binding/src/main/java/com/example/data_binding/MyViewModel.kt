package com.example.data_binding

import android.arch.lifecycle.MutableLiveData
import android.arch.lifecycle.ViewModel

class MyViewModel :ViewModel() {
    var name:MutableLiveData<String> = MutableLiveData<String>().apply { value="hello" }
        get() = field
        set(value) {
            field=value
        }
    fun change(){
        name.value = "world"
    }
}