/*
 * 
 * Copyright (c) 2015, alipay.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.lionel.andfix2.sample.test;

import android.content.Context;
import android.util.Log;
import android.widget.Toast;

/**
 * the class will be fix
 * 
 * copy {@link Fix} to here, and then generate patch (.apatch file)
 * 
 * @author sanping.li@alipay.com
 * 
 */
public class A {
	String s = "s";
	private static O o = new O("a");
	static int i = 10;

	public static String a(String str) {
		Log.e("euler", "fix error");
		return "a";
	}

	public int b(String s1, String s2) {
		Log.e("euler", "fix error");
		Log.e("euler", o.s);
		return 0;
	}

	public int getI() {
		return i;
	}

	public static void showToast(Context context) {
        Log.e("euler", "fix success");
        Toast.makeText(context, "hello andfix2", Toast.LENGTH_SHORT).show();
	}
}
