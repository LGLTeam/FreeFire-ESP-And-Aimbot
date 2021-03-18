package com.mt.team;

import android.app.Activity;
import android.os.Bundle;

import com.mt.team.R;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        StaticActivity.Start(this);
    }
}
