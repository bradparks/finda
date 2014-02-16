#ifndef INCLUDED_sys_FileSystem
#define INCLUDED_sys_FileSystem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(sys,FileSystem)
HX_DECLARE_CLASS2(sys,_FileSystem,FileKind)
namespace sys{


class HXCPP_CLASS_ATTRIBUTES  FileSystem_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FileSystem_obj OBJ_;
		FileSystem_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FileSystem_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileSystem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileSystem"); }

		static Void rename( ::String path,::String newpath);
		static Dynamic rename_dyn();

		static Dynamic stat( ::String path);
		static Dynamic stat_dyn();

		static ::String fullPath( ::String relpath);
		static Dynamic fullPath_dyn();

		static ::sys::_FileSystem::FileKind kind( ::String path);
		static Dynamic kind_dyn();

		static bool isDirectory( ::String path);
		static Dynamic isDirectory_dyn();

		static Array< ::String > readDirectory( ::String path);
		static Dynamic readDirectory_dyn();

		static Dynamic sys_rename;
		static Dynamic &sys_rename_dyn() { return sys_rename;}
		static Dynamic sys_stat;
		static Dynamic &sys_stat_dyn() { return sys_stat;}
		static Dynamic sys_file_type;
		static Dynamic &sys_file_type_dyn() { return sys_file_type;}
		static Dynamic sys_read_dir;
		static Dynamic &sys_read_dir_dyn() { return sys_read_dir;}
		static Dynamic file_full_path;
		static Dynamic &file_full_path_dyn() { return file_full_path;}
};

} // end namespace sys

#endif /* INCLUDED_sys_FileSystem */ 
