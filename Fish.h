/**
 * @file Fish.h
 * @author Mannan Dhillon
 *
 * Class for fish moving saving and loading
 */

#ifndef AQUARIUM_FISH_H
#define AQUARIUM_FISH_H

#include <random>
#include "Item.h"
#include "Aquarium.h"

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:
    /// Fish speed in the X direction
/// in pixels per second
    double mSpeedX;

/// Fish speed in the Y direction
/// in pixels per second
    double mSpeedY;
public:

    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;


/// Assignment operator
    void operator=(const Fish &) = delete;
    /**
   * Get the newest speed for fish
     * @param minX,maxX,minY,maxY
   *
   */
    void NewestSpeed(double minX,double maxX, double minY, double maxY)
    {std::uniform_real_distribution<> distributionX(minX, maxX);
        mSpeedX = distributionX(this->GetAquarium()->GetRandom());
        std::uniform_real_distribution<> distributionY(minY, maxY);
        mSpeedY = distributionY(this->GetAquarium()->GetRandom());
    }
protected:
    Fish(Aquarium *aquarium, const std::wstring &filename);

    void Update(double elapsed);

    wxXmlNode *XmlSave(wxXmlNode *node) override;

    void XmlLoad(wxXmlNode *node) override;
};


#endif //AQUARIUM_FISH_H
