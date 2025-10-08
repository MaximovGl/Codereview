package app.lesson.services;

import java.util.List;
import java.util.Optional;
import app.lesson.models.Audience;
import app.lesson.repositories.AudienceRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;



@Service
public class AudienceService {

    @Autowired
    private AudienceRepository audienceRepository;

    public List<Audience> findAll() {
        return audienceRepository.findAll();
    }

    public Optional<Audience> findById(Long id) {
        return audienceRepository.findById(id);
    }

    public void save(Audience audience) {
        audienceRepository.save(audience);
    }

    public void deleteById(Long id) {
        audienceRepository.deleteById(id);
    }
}