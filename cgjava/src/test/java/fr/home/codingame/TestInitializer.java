package fr.home.codingame;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URI;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by lrhmf on 11/02/2017.
 */
public class TestInitializer {

    public static List<Scanner> getTestsInput(String difficulty, String puzzleName) throws FileNotFoundException {
        List<Scanner> ret = new ArrayList<Scanner>();
        File f;
        String testFolder = "";
        URL testFolderURI = TestInitializer.class.getClassLoader().getResource(difficulty+"/"+puzzleName);
        if (testFolderURI != null) {
            testFolder = testFolderURI.getFile();
        }
        f = new File(testFolder);
        if (!f.isDirectory() || f == null) {
            return null;
        }
        for (File testcase : f.listFiles()) {
                Scanner s = new Scanner(testcase);
                ret.add(s);
        }
        return ret;
    }
}
