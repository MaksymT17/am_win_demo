#pragma once
#include "bitmap_image.hpp"

namespace am
{
	namespace extraction
	{

		// Image Bmp drawer for represantation of Objects
		// allow to draw rectangles based on existing image
		// compared image -> drawn obects rects -> out: visual where objects found
		class BmpDrawer
		{
		public:
			BmpDrawer(const std::string &file)
				: mImage(bitmap_image(file.c_str())), drawer(mImage) {}
			~BmpDrawer() = default;

			inline void drawRectangle(int minW, int minH, int maxW, int maxH)
			{
				drawer.pen_width(3);
				drawer.pen_color(palette_colormap[e_scarlet]);
				drawer.rectangle(minW, minH, maxW, maxH);
			}

			inline void save(const std::string &file) { mImage.save_image(file); }

		private:
			bitmap_image mImage;
			image_drawer drawer;
		};
	} // namespace extraction
} // namespace am
