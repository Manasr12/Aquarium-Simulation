/**
 * @file Aquarium.cpp
 * @author Mannan Dhillon
 */

#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "CatFish.h"
#include "CarpFish.h"
#include "DecorCastle.h"


using namespace std;

/**
* Aquarium Constructor
*/
Aquarium::Aquarium()
{
    mBackground = make_unique<wxBitmap>(
            L"images/background1.png", wxBITMAP_TYPE_ANY);

    // Loop over the rows of items we will create
    // We use the constant here to indicate how
    // many rows we want to create
    const int NumRows = 5;
    for (int r = 0; r<NumRows; r++)
    {
        // There is a row every 64 pixels and
        // we start 150 pixels from the top
        int y = r * 64 + 150;

        // The number of columns starts at 1 and increases as we
        // go down in the Y direction until half way, then decreases.
        // If we had 5 rows, the number of columns for each row
        // will be:  1 2 3 4 1
        int numCols = NumRows / 2 - abs(r - NumRows / 2) + 1;

        // We center the columns on the screen
        int xStart = 512 - (numCols - 1) * 128;


    }
    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());

}



/**
 * Draw the aquarium
 * @param dc The device context to draw on
 */
void Aquarium::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Under the Sea!", 10, 10);

    for (auto item : mItems)
    {
        item->Draw(dc);
    }
}
/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/**
 * Add an item to aquarium
 * @param item item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
    ///boolean to check
    bool OverLap;
    /// x value for to keep track
    int x = InitialX;
    /// y value for to keep track
    int y = InitialY;
    /// first for loop,x and y gets incremented to change location of fish
    for( x,y; ; x = x + 10,y = y + 10)
    {
            /// boolean is false
            OverLap = false;
            /// change the set location
            item->SetLocation(x, y);
            ///second for loop
            for (const auto &fish: mItems)
            {
                ///check distance of item and fish
                if (item->DistanceTo(fish) == 0)
                {
                    /// boolean is true
                    OverLap = true;
                    break;
                }
            }
        /// if boolean is false it breaks
        if(OverLap==false)
        {
            break;
        }
    }
    mItems.push_back(item);
}
/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}
/**
 * Move item to back of aquarium
 * @param item item to move
 */
void Aquarium::MoveToFront(std::shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {

        mItems.erase(loc);
        mItems.push_back(item);
    }

}
/**
 * Save the aquarium as a .aqua XML file.
 *
 * Open an XML file and stream the aquarium data to it.
 *
 * @param filename The filename of the file to save the aquarium to
 */
void Aquarium::Save(const wxString &filename)
{
    wxXmlDocument xmlDoc;

    auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"aqua");
    xmlDoc.SetRoot(root);
    // Iterate over all items and save them
    for (auto item : mItems)
    {
        item->XmlSave(root);
    }

    if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
    {
        wxMessageBox(L"Write to XML failed");
        return;
    }
}
/**
 * Load the aquarium from a .aqua XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the aquarium from.
 */
void Aquarium::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Aquarium file");
        return;
    }

    Clear();
    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"item")
        {
            XmlItem(child);
        }
    }

}
/**
 * Clear the aquarium data.
 *
 * Deletes all known items in the aquarium.
 */
void Aquarium::Clear()
{
mItems.clear();
}
/**
 * Handle a node of type item.
 * @param node XML node
 */
void Aquarium::XmlItem(wxXmlNode *node)
{
    // A pointer for the item we are loading
    shared_ptr<Item> item;

    // We have an item. What type?
    auto type = node->GetAttribute(L"type");
    if (type == L"beta")
    {
        item = make_shared<FishBeta>(this);
    }
    if (type == L"carp")
    {
        item = make_shared<CarpFish>(this);
    }
    if (type == L"cat")
    {
        item = make_shared<CatFish>(this);
    }
    if (type == L"castle")
    {
        item = make_shared<DecorCastle>(this);
    }


    if (item != nullptr)
    {

        Add(item);
        item->XmlLoad(node);

    }

}
/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Aquarium::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}
