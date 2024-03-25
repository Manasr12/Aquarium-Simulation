/**
 * @file Fish.cpp
 * @author Mannan Dhillon
 */
#include"pch.h"
#include <random>
#include "Fish.h"
#include "Aquarium.h"

///max speed in x
const double MaxSpeedX = 10;

///min speed in x
const double MinSpeedX = 20;
///min speed in y
const double MinSpeedY = 30;
///max speed in y
const double MaxSpeedY= 40;
/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
Item(aquarium, filename)
{
    std::uniform_real_distribution<> distributionX(MinSpeedX, MaxSpeedX);
    mSpeedX = distributionX(this->GetAquarium()->GetRandom());
    std::uniform_real_distribution<> distributionY(MinSpeedY, MaxSpeedY);
    mSpeedY = distributionY(this->GetAquarium()->GetRandom());
}
/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
                GetY() + mSpeedY * elapsed);
    if (mSpeedX > 0 && GetX()+GetWidth()/2 >= GetAquarium()->GetWidth()-10)
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX<0);
    }
    if (mSpeedX < 0 && GetX() - GetWidth()/2 <=10)
    {
       mSpeedX = -mSpeedX;
       SetMirror(mSpeedX<0);
    }
    if (mSpeedY > 0 && GetY()+GetHeight()/2 >= GetAquarium()->GetHeight()-10)
    {
        mSpeedY = -mSpeedY;

    }
    if (mSpeedY < 0 && GetY() - GetHeight()/2 <=10){
        mSpeedY = -mSpeedY;
    }
    ///if (mSpeedY)


}
/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode* Fish::XmlSave(wxXmlNode* node)
{
    wxXmlNode* itemNode = Item::XmlSave(node);


    itemNode->AddAttribute(L"speedX", wxString::FromDouble(mSpeedX));
    itemNode->AddAttribute(L"speedY", wxString::FromDouble(mSpeedY));

    return itemNode;
}
/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Fish::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);

    node->GetAttribute(L"speedX", L"0").ToDouble(&mSpeedX);
    node->GetAttribute(L"speedY", L"0").ToDouble(&mSpeedY);
}