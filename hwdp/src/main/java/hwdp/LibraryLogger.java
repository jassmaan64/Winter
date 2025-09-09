package hwdp;
import java.util.ArrayList;
import java.util.List;

public class LibraryLogger {
    private static  LibraryLogger instance;
    // TODO?
    private final List<String> writtenLines;

    private LibraryLogger()
    {
        ExpensiveComputeToy.performExpensiveLogSetup();
        writtenLines = new ArrayList<>();
    }

    public void writeLine(String line) {
        // TODO?
        System.out.println("LibraryLogger: " + line);
        writtenLines.add(line);
    }

    public String[] getWrittenLines() {
        // TODO?
        return writtenLines.toArray(new String[0]);
        // return null;
    }

    public void clearWriteLog() {
        writtenLines.clear();
        // TODO?
    }
    
    public static LibraryLogger getInstance() {
        // TODO?
        // return null;
        if(instance == null)
        {
            instance = new LibraryLogger();
            // ExpensiveComputeToy.performExpensiveLogSetup();
        }
        return instance;
    }
}
