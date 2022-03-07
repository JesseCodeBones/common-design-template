package com.example.data_binding

import android.arch.lifecycle.ViewModelProvider
import android.databinding.DataBindingUtil
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import com.example.data_binding.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {



    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        DataBindingUtil.setContentView<ActivityMainBinding>(this, R.layout.activity_main).also {
            it.viewModel = MyViewModel()
            it.lifecycleOwner = this
        }
    }


}