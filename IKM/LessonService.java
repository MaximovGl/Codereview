package app.lesson.services;

import java.util.List;
import java.util.Optional;
import app.lesson.models.Lesson;
import app.lesson.repositories.LessonRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class LessonService {

    @Autowired
    private LessonRepository lessonRepository;

    public List<Lesson> findAll() {
        return lessonRepository.findAll();
    }

    public Optional<Lesson> findById(Long id) {
        return lessonRepository.findById(id);
    }

    public void save(Lesson lesson) {
        lessonRepository.save(lesson);
    }

    public void deleteById(Long id) {
        lessonRepository.deleteById(id);
    }

    public boolean isStudentUsedInLesson(Long studId) {
        return lessonRepository.existsByStudentId(studId);
    }

    public boolean isAudienceUsedInLesson(Long audId) {
        return lessonRepository.existsByAudienceId(audId);
    }
}

