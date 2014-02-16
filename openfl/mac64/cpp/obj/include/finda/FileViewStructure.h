#ifndef INCLUDED_finda_FileViewStructure
#define INCLUDED_finda_FileViewStructure

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(finda,FileViewStructure)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  FileViewStructure_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FileViewStructure_obj OBJ_;
		FileViewStructure_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FileViewStructure_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileViewStructure_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileViewStructure"); }

		static Dynamic construct( ::flash::display::Sprite g2D,::String path,int x,int y);
		static Dynamic construct_dyn();

};

} // end namespace finda

#endif /* INCLUDED_finda_FileViewStructure */ 
