package app.lesson.controllers;

import app.lesson.models.Lesson;
import app.lesson.models.Student;
import app.lesson.models.Audience;
import app.lesson.services.LessonService;
import app.lesson.services.StudentService;
import app.lesson.services.AudienceService;
import app.lesson.dto.LessonDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;

import jakarta.validation.Valid;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

@Controller
@RequestMapping("/Lessons")
public class LessonController {

    @Autowired
    private LessonService lessonService;

    @Autowired
    private StudentService studentService;

    @Autowired
    private AudienceService audienceService;

    @GetMapping
    public String getAllLessons(Model model) {
        List<Lesson> lessons = lessonService.findAll();
        List<LessonDTO> lessonDtos = lessons.stream().map(Lesson -> {
            String AudienceName = Lesson.getAudience().getBuilding();
            String StudentInfo = Lesson.getStudent().getFirstname() + " " + Lesson.getStudent().getLastname();
            return new LessonDTO(Lesson.getId(), AudienceName, StudentInfo, Lesson.getLesson());
        }).collect(Collectors.toList());
        model.addAttribute("lessons", lessonDtos);
        return "Lesson_list";
    }

    @GetMapping("/new")
    public String showCreateLessonForm(Model model) {
        model.addAttribute("lesson", new Lesson());
        model.addAttribute("students", studentService.findAll());
        model.addAttribute("audiences", audienceService.findAll());

        return "Lesson_add";
    }

    @PostMapping("/new")
    public String createLesson(@Valid @ModelAttribute Lesson lesson, BindingResult bindingResult, Model model) {
        if (bindingResult.hasErrors()) {
            model.addAttribute("students", studentService.findAll());
            model.addAttribute("audiences", audienceService.findAll());
            return "Lesson_add";
        }
        Optional<Student> studentOpt = studentService.findById(lesson.getStudent().getId());
        if (studentOpt.isEmpty()) {
            System.out.println("Invalid Student ID: " + lesson.getStudent().getId());
            model.addAttribute("errorMessage", "Invalid Student ID: " + lesson.getStudent().getId());
            model.addAttribute("students", studentService.findAll());
            model.addAttribute("audiences", audienceService.findAll());
            return "Lesson_add";
        }

        Optional<Audience> audienceOpt = audienceService.findById(lesson.getAudience().getId());
        if (audienceOpt.isEmpty()) {
            System.out.println("Invalid Audience ID: " + lesson.getAudience().getId());
            model.addAttribute("errorMessage", "Invalid Audience ID: " + lesson.getAudience().getId());
            model.addAttribute("students", studentService.findAll());
            model.addAttribute("audiences", audienceService.findAll());
            return "Lesson_add";
        }

        lesson.setStudent(studentOpt.get());
        lesson.setAudience(audienceOpt.get());
        lessonService.save(lesson);
        return "redirect:/Lessons";
    }

    @GetMapping("/edit/{id}")
    public String showEditLessonForm(@PathVariable Long id, Model model) {
        Optional<Lesson> lessonOpt = lessonService.findById(id);
        if (lessonOpt.isEmpty()) {
            System.out.println("Invalid Lesson ID: " + id);
            model.addAttribute("error", "Failed to fetch Lesson for editing");
            return "redirect:/Lessons";
        }

        Lesson lesson = lessonOpt.get();
        model.addAttribute("lesson", lesson);
        model.addAttribute("students", studentService.findAll());
        model.addAttribute("audiences", audienceService.findAll());
        return "Lesson_edit";
    }

    @PostMapping("/edit/{id}")
    public String updateLesson(@PathVariable Long id, @ModelAttribute Lesson lesson, BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return "Lesson_edit";
        }
        try {
            lesson.setId(id);
            lessonService.save(lesson);
        } catch (Exception e) {
            e.printStackTrace();
            return "Lesson_edit";
        }
        return "redirect:/Lessons";
    }

    @GetMapping("/delete/{id}")
    public String deleteLesson(@PathVariable Long id) {
        lessonService.deleteById(id);
        return "redirect:/Lessons";
    }
}
