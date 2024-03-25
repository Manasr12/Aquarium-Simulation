/**
 * @file CatFish.h
 * @author Mannan Dhillon
 *
 * Class for a fish of type Beta
 */
#ifndef AQUARIUM_CATFISH_H
#define AQUARIUM_CATFISH_H

#include "Item.h"
#include "Fish.h"

/**
 * Class for a fish of type Beta
 */
class CatFish : public Fish {
private:


public:
    /// Default constructor (disabled)
    CatFish() = delete;

    /// Copy constructor (disabled)
    CatFish(const CatFish &) = delete;

    /// Assignment operator
    void operator=(const CatFish &) = delete;

    CatFish(Aquarium* aquarium);


    wxXmlNode* XmlSave(wxXmlNode* node) override;
};
#endif //AQUARIUM_CATFISH_H
