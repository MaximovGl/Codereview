package app.lesson.repositories;

import app.lesson.models.Audience;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AudienceRepository extends JpaRepository<Audience, Long> {
}
