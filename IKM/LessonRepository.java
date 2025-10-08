package app.lesson.repositories;

import app.lesson.models.Lesson;
import org.springframework.data.jpa.repository.JpaRepository;

public interface LessonRepository extends JpaRepository<Lesson, Long> {

    boolean existsByStudentId(Long studentId);
    boolean existsByAudienceId(Long audienceId);
}