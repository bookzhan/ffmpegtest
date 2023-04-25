package com.example.ffmpegtest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.example.ffmpegtest.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'ffmpegtest' library on application startup.
    static {
        System.loadLibrary("bzffmpeg");
        System.loadLibrary("ffmpegtest");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
    }

    /**
     * A native method that is implemented by the 'ffmpegtest' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public void test(View view) {
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }
}