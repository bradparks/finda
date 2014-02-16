#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys__FileSystem_FileKind
#include <sys/_FileSystem/FileKind.h>
#endif
namespace sys{

Void FileSystem_obj::__construct()
{
	return null();
}

FileSystem_obj::~FileSystem_obj() { }

Dynamic FileSystem_obj::__CreateEmpty() { return  new FileSystem_obj; }
hx::ObjectPtr< FileSystem_obj > FileSystem_obj::__new()
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

Dynamic FileSystem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

Void FileSystem_obj::rename( ::String path,::String newpath){
{
		HX_STACK_PUSH("FileSystem::rename","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",37);
		HX_STACK_ARG(path,"path");
		HX_STACK_ARG(newpath,"newpath");
		HX_STACK_LINE(37)
		if (((::sys::FileSystem_obj::sys_rename(path,newpath) == null()))){
			HX_STACK_LINE(39)
			hx::Throw ((((HX_CSTRING("Could not rename:") + path) + HX_CSTRING(" to ")) + newpath));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FileSystem_obj,rename,(void))

Dynamic FileSystem_obj::stat( ::String path){
	HX_STACK_PUSH("FileSystem::stat","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",42);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(43)
	Dynamic s = ::sys::FileSystem_obj::sys_stat(path);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(44)
	if (((s == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",45);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("gid") , (int)0,false);
					__result->Add(HX_CSTRING("uid") , (int)0,false);
					__result->Add(HX_CSTRING("atime") , ::Date_obj::fromTime((int)0),false);
					__result->Add(HX_CSTRING("mtime") , ::Date_obj::fromTime((int)0),false);
					__result->Add(HX_CSTRING("ctime") , ::Date_obj::fromTime((int)0),false);
					__result->Add(HX_CSTRING("dev") , (int)0,false);
					__result->Add(HX_CSTRING("ino") , (int)0,false);
					__result->Add(HX_CSTRING("nlink") , (int)0,false);
					__result->Add(HX_CSTRING("rdev") , (int)0,false);
					__result->Add(HX_CSTRING("size") , (int)0,false);
					__result->Add(HX_CSTRING("mode") , (int)0,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(45)
		return _Function_2_1::Block();
	}
	HX_STACK_LINE(46)
	s->__FieldRef(HX_CSTRING("atime")) = ::Date_obj::fromTime((1000.0 * s->__Field(HX_CSTRING("atime"),true)));
	HX_STACK_LINE(47)
	s->__FieldRef(HX_CSTRING("mtime")) = ::Date_obj::fromTime((1000.0 * s->__Field(HX_CSTRING("mtime"),true)));
	HX_STACK_LINE(48)
	s->__FieldRef(HX_CSTRING("ctime")) = ::Date_obj::fromTime((1000.0 * s->__Field(HX_CSTRING("ctime"),true)));
	HX_STACK_LINE(49)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,stat,return )

::String FileSystem_obj::fullPath( ::String relpath){
	HX_STACK_PUSH("FileSystem::fullPath","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",52);
	HX_STACK_ARG(relpath,"relpath");
	HX_STACK_LINE(52)
	return ::String(::sys::FileSystem_obj::file_full_path(relpath));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,fullPath,return )

::sys::_FileSystem::FileKind FileSystem_obj::kind( ::String path){
	HX_STACK_PUSH("FileSystem::kind","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",56);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(57)
	::String k = ::sys::FileSystem_obj::sys_file_type(path);		HX_STACK_VAR(k,"k");
	struct _Function_1_1{
		inline static ::sys::_FileSystem::FileKind Block( ::String &k){
			HX_STACK_PUSH("*::closure","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",58);
			{
				HX_STACK_LINE(58)
				::String _switch_1 = (k);
				if (  ( _switch_1==HX_CSTRING("file"))){
					HX_STACK_LINE(59)
					return ::sys::_FileSystem::FileKind_obj::kfile;
				}
				else if (  ( _switch_1==HX_CSTRING("dir"))){
					HX_STACK_LINE(60)
					return ::sys::_FileSystem::FileKind_obj::kdir;
				}
				else  {
					HX_STACK_LINE(61)
					return ::sys::_FileSystem::FileKind_obj::kother(k);
				}
;
;
			}
			return null();
		}
	};
	HX_STACK_LINE(58)
	return _Function_1_1::Block(k);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,kind,return )

bool FileSystem_obj::isDirectory( ::String path){
	HX_STACK_PUSH("FileSystem::isDirectory","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",65);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(65)
	return (::sys::FileSystem_obj::kind(path) == ::sys::_FileSystem::FileKind_obj::kdir);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,isDirectory,return )

Array< ::String > FileSystem_obj::readDirectory( ::String path){
	HX_STACK_PUSH("FileSystem::readDirectory","/usr/lib/haxe/std/cpp/_std/sys/FileSystem.hx",89);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(89)
	return ::sys::FileSystem_obj::sys_read_dir(path);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,readDirectory,return )

Dynamic FileSystem_obj::sys_rename;

Dynamic FileSystem_obj::sys_stat;

Dynamic FileSystem_obj::sys_file_type;

Dynamic FileSystem_obj::sys_read_dir;

Dynamic FileSystem_obj::file_full_path;


FileSystem_obj::FileSystem_obj()
{
}

void FileSystem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileSystem);
	HX_MARK_END_CLASS();
}

void FileSystem_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic FileSystem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stat") ) { return stat_dyn(); }
		if (HX_FIELD_EQ(inName,"kind") ) { return kind_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rename") ) { return rename_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fullPath") ) { return fullPath_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_stat") ) { return sys_stat; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sys_rename") ) { return sys_rename; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isDirectory") ) { return isDirectory_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_read_dir") ) { return sys_read_dir; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"readDirectory") ) { return readDirectory_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_file_type") ) { return sys_file_type; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"file_full_path") ) { return file_full_path; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileSystem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"sys_stat") ) { sys_stat=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sys_rename") ) { sys_rename=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_read_dir") ) { sys_read_dir=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"sys_file_type") ) { sys_file_type=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"file_full_path") ) { file_full_path=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileSystem_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("rename"),
	HX_CSTRING("stat"),
	HX_CSTRING("fullPath"),
	HX_CSTRING("kind"),
	HX_CSTRING("isDirectory"),
	HX_CSTRING("readDirectory"),
	HX_CSTRING("sys_rename"),
	HX_CSTRING("sys_stat"),
	HX_CSTRING("sys_file_type"),
	HX_CSTRING("sys_read_dir"),
	HX_CSTRING("file_full_path"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileSystem_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_rename,"sys_rename");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_stat,"sys_stat");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_file_type,"sys_file_type");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_read_dir,"sys_read_dir");
	HX_MARK_MEMBER_NAME(FileSystem_obj::file_full_path,"file_full_path");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileSystem_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_rename,"sys_rename");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_stat,"sys_stat");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_file_type,"sys_file_type");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_read_dir,"sys_read_dir");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::file_full_path,"file_full_path");
};

Class FileSystem_obj::__mClass;

void FileSystem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.FileSystem"), hx::TCanCast< FileSystem_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileSystem_obj::__boot()
{
	sys_rename= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_rename"),(int)2);
	sys_stat= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_stat"),(int)1);
	sys_file_type= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_file_type"),(int)1);
	sys_read_dir= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_read_dir"),(int)1);
	file_full_path= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_full_path"),(int)1);
}

} // end namespace sys
