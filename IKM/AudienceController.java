package app.lesson.controllers;

import app.lesson.services.AudienceService;
import app.lesson.services.LessonService;
import app.lesson.models.Audience;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.Optional;

@Controller
@RequestMapping("/Audiences")
public class AudienceController {

    @Autowired
    private AudienceService audienceService;

    @Autowired
    private LessonService lessonService;

    @GetMapping
    public String getAllAudiences(Model model) {
        model.addAttribute("audiences", audienceService.findAll());
        return "audiences_list";
    }

    @GetMapping("/new")
    public String showAddAudienceForm(Model model) {
        model.addAttribute("audience", new Audience());
        return "audience_add";
    }

    @PostMapping("/new")
    public String addAudience(@ModelAttribute("audience")  Audience audience, Model model) {
        try {
            audienceService.save(audience);
            return "redirect:/Audiences";
        } catch (Exception e) {
            model.addAttribute("errorMessage", "Error adding audience.");
            return "audience_add";
        }
    }

    @GetMapping("/edit/{id}")
    public String editAudience(@PathVariable("id") Long id, Model model) {
        Optional<Audience> audienceOptional = audienceService.findById(id);
        if (audienceOptional.isPresent()) {
            model.addAttribute("audience", audienceOptional.get());
            return "audience_edit";
        } else {
            return "audience_not_found";
        }
    }

    @PostMapping("/edit/{id}")
    public String saveAudience(@PathVariable("id") Long id, @ModelAttribute Audience audience) {
        audience.setId(id);
        audienceService.save(audience);
        return "redirect:/Audiences";
    }

    @PostMapping("/delete/{id}")
    public String deleteAudience(@PathVariable("id") Long id) {
        //Это условие нужно чтобы не давать удалить аудиторию если есть запись о её участии в уроке.
        if (lessonService.isAudienceUsedInLesson(id)) {
            return "redirect:/Audiences?error=Audience+is+used+in+a+lesson";
        }
        audienceService.deleteById(id);
        return "redirect:/Audiences";
    }
}