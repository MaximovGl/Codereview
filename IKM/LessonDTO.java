package app.lesson.dto;

public class LessonDTO {
    private Long id;
    private String building;
    private String studentInfo;
    private String lesson;

    public LessonDTO(Long id, String Building, String StudentInfo, String Lesson) {
        this.id = id;
        this.building = Building;
        this.studentInfo = StudentInfo;
        this.lesson = Lesson;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getBuilding() {
        return building;
    }

    public void setBuilding(String Building) {
        this.building = Building;
    }

    public String getStudentInfo() {
        return studentInfo;
    }

    public void setStudentInfo(String StudentInfo) {
        this.studentInfo = StudentInfo;
    }

    public String getLesson() {
        return lesson;
    }

    public void setLesson(String Lesson) {
        this.lesson = Lesson;
    }
}
