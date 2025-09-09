package hw3;

import java.time.Duration;
import java.time.LocalDateTime;

public class Task {
    private String name;
    private LocalDateTime starTime;
    private LocalDateTime endTime;
    private String description;
    private String size;

    /**
     * @return String return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return LocalDateTime return the starTime
     */
    public LocalDateTime getStarTime() {
        return starTime;
    }

    /**
     * @param starTime the starTime to set
     */
    public void setStarTime(LocalDateTime starTime) {
        this.starTime = starTime;
    }

    /**
     * @return LocalDateTime return the endTime
     */
    public LocalDateTime getEndTime() {
        return endTime;
    }

    /**
     * @param endTime the endTime to set
     */
    public void setEndTime(LocalDateTime endTime) {
        this.endTime = endTime;
    }

    // /**
    // * @return string return the description
    // */
    // public string getDescription() {
    // return description;
    // }

    /**
     * @param description the description to set
     */
    public void setDescription(String description) {
        this.description = description;
    }

    // /**
    // * @return String return the size
    // */
    // public String getSize() {
    // return size;
    // }

    /**
     * @param size the size to set
     */
    public void setSize(String size) {
        this.size = size;
    }

    public long getDuration() {
        if (starTime != null && endTime != null) {
            return Duration.between(starTime, endTime).getSeconds();
        }
        return 0;
    }

}
