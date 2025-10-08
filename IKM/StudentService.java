package app.lesson.services;

import app.lesson.models.Student;
import app.lesson.repositories.StudentRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Optional;

@Service
public class StudentService {

    @Autowired
    private StudentRepository studentRepository;

    public List<Student> findAll() {
        List<Student> Students = studentRepository.findAll();
        if (Students.isEmpty()) {
            System.out.println("No Students found in the database.");
        }
        return Students;
    }

    public Optional<Student> findById(Long id) {
        Optional<Student> student = studentRepository.findById(id);
        if (student.isEmpty()) {
            System.out.println("Student with ID " + id + " not found.");
        }
        return student;
    }

    public void save(Student student) {
        if (student == null) {
            System.out.println("Cannot save null Student object.");
            return;
        }
        studentRepository.save(student);
        System.out.println("Student saved with ID: " + student.getId());
    }

    public void deleteById(Long id) {
        Optional<Student> student = studentRepository.findById(id);
        if (student.isEmpty()) {
            System.out.println("Student with ID " + id + " not found for deletion.");
            return;
        }
        studentRepository.deleteById(id);
        System.out.println("Student with ID " + id + " deleted.");
    }
}
