#include "FontManager.h"
#include "TextureFont.h"
#include "VectorFont.h"
#include "GuiScreen.h"

FontManager::FontManager()
{
	FT_Error err = FT_Init_FreeType(&m_library);
	if (err != 0) {
		fprintf(stderr, "Couldn't create FreeType library context (%d)\n", err);
		abort();
	}
}

FontManager::~FontManager()
{
	FT_Done_FreeType(m_library);
}

TextureFont *FontManager::GetTextureFont(const std::string &name)
{
	std::map<std::string, TextureFont*>::iterator i = m_textureFonts.find(name);
	if (i != m_textureFonts.end())
		return (*i).second;

	// XXX temporary until the config stuff gets merged into this
    float scale[2];
	Gui::Screen::GetCoords2Pixels(scale);

	TextureFont *font = new TextureFont(*this, (PIONEER_DATA_DIR "/fonts/" + name + ".ttf").c_str(), int(12/scale[0]), int(12/scale[1]));
	m_textureFonts.insert( std::make_pair(name, font) );

	return font;
}

VectorFont *FontManager::GetVectorFont(const std::string &name)
{
	std::map<std::string, VectorFont*>::iterator i = m_vectorFonts.find(name);
	if (i != m_vectorFonts.end())
		return (*i).second;

	VectorFont *font = new VectorFont(*this, (PIONEER_DATA_DIR "/fonts/" + name + ".ttf").c_str());
	m_vectorFonts.insert( std::make_pair(name, font) );

	return font;
}