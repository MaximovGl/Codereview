package app.lesson.controllers;

import app.lesson.services.LessonService;
import app.lesson.models.Student;
import app.lesson.services.StudentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.Optional;

@Controller
@RequestMapping("/Students")
public class StudentController {

    @Autowired
    private StudentService studentService;

    @Autowired
    private LessonService lessonService;

    @GetMapping
    public String getAllStudents(Model model) {
        model.addAttribute("students", studentService.findAll());
        return "students_list";
    }

    @GetMapping("/new")
    public String showAddStudentForm(Model model) {
        model.addAttribute("student", new Student());
        return "student_add";
    }

    @PostMapping("/new")
    public String addStudent(@ModelAttribute("student") Student student, Model model) {
        try {
            studentService.save(student);
            return "redirect:/Students";
        } catch (Exception e) {
            model.addAttribute("errorMessage", "Failed to add student.");
            return "student_add";
        }
    }

    @GetMapping("/edit/{id}")
    public String editStudent(@PathVariable("id") Long id, Model model) {
        Optional<Student> studentOptional = studentService.findById(id);
        if (studentOptional.isPresent()) {
            model.addAttribute("student", studentOptional.get());
            return "student_edit";
        } else {
            return "student_not_found";
        }
    }

    @PostMapping("/edit/{id}")
    public String saveStudent(@PathVariable("id") Long id, @ModelAttribute Student student) {
        student.setId(id);
        studentService.save(student);
        return "redirect:/Students";
    }

    @PostMapping("/delete/{id}")
    public String deleteStudent(@PathVariable("id") Long id) {
        //Из-за волнения на паре запамятовал и перепутал момент с каскадным удаленеием.
        //Это условие не дает удалить студента если есть запись о его участии в уроке.
        if (lessonService.isStudentUsedInLesson(id)) {
            return "redirect:/Students?error=Student+is+used+in+a+lesson";
        }
        studentService.deleteById(id);
        return "redirect:/Students";
    }
}