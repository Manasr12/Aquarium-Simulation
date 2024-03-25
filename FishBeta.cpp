/**
 * @file FishBeta.cpp
 * @author Mannan Dhillon
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"
#include <string>
#include "Fish.h"

using namespace std;
/// beta fish max speed x
const double MaxSpeedX =5;
/// beta fish min speed y
const double MinSpeedY =5;
/// beta fish max speed y
const double MaxSpeedY = 10;
/// beta fish min speed for x
const double MinSpeedX = 10;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
    double betaSpeedMaxX = MaxSpeedX + 20;
    double betaSpeedMinY = MinSpeedY + 10;
    double betaSpeedMaxY = MaxSpeedY + 10;
    double betaSpeedMinX = MinSpeedX + 10;
    NewestSpeed(betaSpeedMinX, betaSpeedMaxX,betaSpeedMinY,betaSpeedMaxY);
}
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{

    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"beta");
    return itemNode;


}


