//
// Created by vanish2 on 12.12.23.
//

#ifndef LAB3_ARTIFACT_H
#define LAB3_ARTIFACT_H

#include "Creature.h"

class Artifact {
private:
    Primary influence;

public:
    Artifact() = default;
    virtual ~Artifact() = default;

    /**
     * @breif Getter for influence of Artifact
     * @return Primary that means how Artifact influences on user
     */
    [[nodiscard]] Primary get_influence() const;

    /**
     * @brief Loads data about Artifact from JSON object
     * @param data JSON object
     */
    void be_loaded(json data);
};


#endif //LAB3_ARTIFACT_H
