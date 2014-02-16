#ifndef INCLUDED_finda_Georgia
#define INCLUDED_finda_Georgia

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/text/Font.h>
HX_DECLARE_CLASS1(finda,Georgia)
HX_DECLARE_CLASS2(flash,text,Font)
HX_DECLARE_CLASS2(flash,text,FontStyle)
HX_DECLARE_CLASS2(flash,text,FontType)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  Georgia_obj : public ::flash::text::Font_obj{
	public:
		typedef ::flash::text::Font_obj super;
		typedef Georgia_obj OBJ_;
		Georgia_obj();
		Void __construct(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type);

	public:
		static hx::ObjectPtr< Georgia_obj > __new(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Georgia_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Georgia"); }

		static ::String resourceName;
};

} // end namespace finda

#endif /* INCLUDED_finda_Georgia */ 
