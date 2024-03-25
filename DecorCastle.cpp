/**
 * @file DecorCastle.cpp
 * @author Mannan Dhillon
 */

#include "pch.h"
#include "Aquarium.h"
#include "DecorCastle.h"
#include <string>
using namespace std;

/// Fish filename
const wstring DecorCastleImageName = L"images/castle.png";


/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorCastleImageName)
{
}
/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"type", L"castle");
    return itemNode;
}