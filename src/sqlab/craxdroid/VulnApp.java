package sqlab.craxdroid.vulnapp;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class VulnApp extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        main();
        finish();
    }

    static {
        System.loadLibrary("VulnApp");
    }

    public static native int main();
}

