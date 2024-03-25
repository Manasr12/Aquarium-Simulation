/**
 * @file CatFish.cpp
 * @author Mannan Dhillon
 */

#include "pch.h"
#include "Aquarium.h"
#include "CatFish.h"
#include <string>
using namespace std;
/// catfish max speed in x
const double MaxSpeedX =10;
/// catfish min speed in y
const double MinSpeedY =10;
///  catfish max speed in y
const double MaxSpeedY = 10;
/// catfish min speed in x
const double MinSpeedX = 10;

/// Fish filename
const wstring CatFishImageName = L"images/catfish.png";



/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
CatFish::CatFish(Aquarium *aquarium) : Fish(aquarium, CatFishImageName)
{
    double CatFishSpeedMaxX = MaxSpeedX + 20;
    double CatFishSpeedMinY = MinSpeedY + 10;
    double CatFishSpeedMaxY = MaxSpeedY + 10;
    double CatFishSpeedMinX = MinSpeedX + 10;
    NewestSpeed(CatFishSpeedMinX, CatFishSpeedMaxX,CatFishSpeedMinY ,CatFishSpeedMaxY);
}
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* CatFish::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"cat");
    return itemNode;
}



