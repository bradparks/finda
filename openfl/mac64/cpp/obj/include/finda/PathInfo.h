#ifndef INCLUDED_finda_PathInfo
#define INCLUDED_finda_PathInfo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(finda,PathInfo)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  PathInfo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PathInfo_obj OBJ_;
		PathInfo_obj();
		Void __construct(::String path_);

	public:
		static hx::ObjectPtr< PathInfo_obj > __new(::String path_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PathInfo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PathInfo"); }

		virtual Void tracePaths( );
		Dynamic tracePaths_dyn();

		virtual Void changePath( ::String path_);
		Dynamic changePath_dyn();

		::String parent;
		::String full;
		::String path;
};

} // end namespace finda

#endif /* INCLUDED_finda_PathInfo */ 
