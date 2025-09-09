package hwdp;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.mock;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.time.InstantSource;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class Student_919250077_Test {
    @BeforeEach
    public void resetLog() {
        LibraryLogger.getInstance().clearWriteLog();
    }

    @Test
    public void Junit5() {
        LibraryBook book = new LibraryBook("Dungens and Dragons");

        assertEquals(OnShelf.getInstance(), book.getState());

        book.issue();
        assertEquals(Borrowed.getInstance(), book.getState());

        book.returnIt();
        assertEquals(GotBack.getInstance(), book.getState());

        book.shelf();
        assertEquals(OnShelf.getInstance(), book.getState());

    }
}
