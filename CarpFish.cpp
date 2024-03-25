/**
 * @file CarpFish.cpp
 * @author Mannan Dhillon
 */

#include "pch.h"
#include "Aquarium.h"
#include "CarpFish.h"
#include <string>
using namespace std;
///carp max speed in x
const double MaxSpeedX =20;
///carp max speed in y
const double MinSpeedY =20;
///carp max speed in y
const double MaxSpeedY = 10;
///carp min speed in x
const double MinSpeedX = 10;

/// Fish filename
const wstring CarpFishImageName = L"images/carp.png";


/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
CarpFish::CarpFish(Aquarium *aquarium) : Fish(aquarium, CarpFishImageName)
{

    double CarpFishSpeedMaxX = MaxSpeedX + 20;
    double CarpFishSpeedMinY = MinSpeedY + 10;
    double CarpFishSpeedMaxY = MaxSpeedY + 10;
    double CarpFishSpeedMinX = MinSpeedX + 10;
    NewestSpeed(CarpFishSpeedMinX, CarpFishSpeedMaxX,CarpFishSpeedMinY,CarpFishSpeedMaxY);
}
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* CarpFish::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"carp");
    return itemNode;
}