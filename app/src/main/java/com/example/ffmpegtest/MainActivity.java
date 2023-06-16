package com.example.ffmpegtest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.example.ffmpegtest.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "bz_" + MainActivity.class.getSimpleName();

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
        testCallBack(new OnActionListener() {
            @Override
            public void progress(float progress) {
                Log.d(TAG, "native call back progress=" + progress);
            }
        });
    }

    /**
     * A native method that is implemented by the 'ffmpegtest' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void testCallBack(OnActionListener onActionListener);

    public void test(View view) {
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }

    public interface OnActionListener {
        void progress(float progress);
    }
}