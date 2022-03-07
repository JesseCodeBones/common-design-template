# android DataBinding
data binding 是基于[LiveData](https://developer.android.google.cn/topic/libraries/architecture/livedata?hl=zh-cn)的一种MVC的实现方式  

## 步骤和意义
1. 激活databinding

    ```
    android{
        dataBinding{
            enabled=true
        }
    }
    ```

2. 激活后， 每个activty xml可以refactor成databinding形式
3. 系统会自动生成binding类，比如activity_main.xml就会生成`ActivityMainBinding`  
4. 创建自定义ViewModel
    ```
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
    ```
5. 将ViewModel与xml绑定  
    ```
    <data>
        <variable
            name="viewModel"
            type="com.example.data_binding.MyViewModel" />
    </data>
    ```  
    ```
    <TextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="@={viewModel.name}"
        />
    <Button
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:onClick="@{()->viewModel.change()}"
        android:text="change age" />
    ```
6. 在activity中实现绑定：  
    ```
        DataBindingUtil.setContentView<ActivityMainBinding>(this, R.layout.activity_main).also {
            it.viewModel = MyViewModel()
            it.lifecycleOwner = this
        }
    ```

这样就实现了双向绑定