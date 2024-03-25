/**
 * @file CarpFish.h
 * @author Mannan Dhillon
 *
 * Class for a fish of type Beta
 */
#ifndef AQUARIUM_CARPFISH_H
#define AQUARIUM_CARPFISH_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for a fish of type Beta
 */
class CarpFish : public Fish {
private:



public:
    /// Default constructor (disabled)
    CarpFish() = delete;

    /// Copy constructor (disabled)
    CarpFish(const CarpFish &) = delete;

    /// Assignment operator
    void operator=(const CarpFish &) = delete;

    CarpFish(Aquarium* aquarium);


    wxXmlNode* XmlSave(wxXmlNode* node) override;
};
#endif //AQUARIUM_CARPFISH_H
