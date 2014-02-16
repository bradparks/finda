#ifndef INCLUDED_finda_FileViewCreatorFL
#define INCLUDED_finda_FileViewCreatorFL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(finda,BitmapTextCreator)
HX_DECLARE_CLASS1(finda,FileViewCreatorFL)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  FileViewCreatorFL_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FileViewCreatorFL_obj OBJ_;
		FileViewCreatorFL_obj();
		Void __construct(::flash::display::Sprite g2D,int x_);

	public:
		static hx::ObjectPtr< FileViewCreatorFL_obj > __new(::flash::display::Sprite g2D,int x_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileViewCreatorFL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileViewCreatorFL"); }

		virtual Dynamic create( ::flash::display::Sprite g2D,Dynamic file,::String tx,int h,int c);
		Dynamic create_dyn();

		int x;
		::finda::BitmapTextCreator bitmapTextCreator;
};

} // end namespace finda

#endif /* INCLUDED_finda_FileViewCreatorFL */ 
