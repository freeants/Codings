

import java.io.*;

public class WindowsSystemInformation {
    static String get() throws IOException {
        Runtime runtime = Runtime.getRuntime();
        Process process = runtime.exec("systeminfo");
        BufferedReader systemInformationReader = new BufferedReader(new InputStreamReader(process.getInputStream()));

        StringBuilder stringBuilder = new StringBuilder();
        String line;

        while ((line = systemInformationReader.readLine()) != null) {
            stringBuilder.append(line);
            stringBuilder.append(System.lineSeparator());
        }

        return stringBuilder.toString().trim();
    }

    public static void main(String[] args) throws IOException {
        System.out.print(get());
    }
}