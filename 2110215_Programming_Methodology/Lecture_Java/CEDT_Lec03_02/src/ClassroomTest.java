import org.junit.After;
import org.junit.Before;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class ClassroomTest {

    Classroom c1;

    @Before
    public     // Before the test
    void setUp()
    {
        Classroom c1 = new Classroom();
    }

    @After
    public void cleanUp()
    {
        Classroom c1 = new Classroom();
    }

    @BeforeEach
    void initialClassroom()
    {
        Classroom c1 = new Classroom();
    }

    @AfterEach
    void initialClassroom()
    {
        Classroom c1 = new Classroom();
    }

    @Test
    void testConstructor() {
//        Classroom c1 = new Classroom();
        assertEquals(0, c1.sizeOfStudents());
    }

    @Test
    void testAddStudent() {
//        Classroom c1 = new Classroom();
        assertEquals(0, c1.sizeOfStudents());

        c1.addStudent("Aj.Toe");
        assertEquals(1, c1.sizeOfStudents());
        assertEquals("Aj.Toe", c1.getStudents().getFirst());
        assertTrue(c1.getStudents().getFirst().equals("Aj.Toe"));
        assertFalse(c1.getStudents().getFirst().equals("Aj.Chate"));
    }

    @Test
    void testEtc() {
        Classroom c1 = new Classroom();
        assertThrows(IndexOutOfBoundsException.class, () -> {
            System.out.println(c1.getStudents().get(100));
        });
    }
}
