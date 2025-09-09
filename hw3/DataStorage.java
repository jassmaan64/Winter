package hw3;

import java.util.*;
import java.io.*;

public class DataStorage {
    // private String fileName = "tasks.txt";

    private String fileName;

    public DataStorage(String filena) {
        fileName = filena;
    }

    public void writeTask(String taskType, String taskName, String... details) {

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            writer.write(taskType + " " + taskName);
            for (String detail : details) {
                writer.write(" " + detail);
            }
            writer.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public List<String> readTask() {
        List<String> taskList = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                taskList.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return taskList;
    }
}
