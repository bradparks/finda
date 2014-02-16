#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_finda_PathInfo
#include <finda/PathInfo.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
namespace finda{

Void PathInfo_obj::__construct(::String path_)
{
HX_STACK_PUSH("PathInfo::new","finda/PathInfo.hx",4);
{
	HX_STACK_LINE(6)
	this->path = HX_CSTRING("./");
	HX_STACK_LINE(11)
	this->changePath(path_);
}
;
	return null();
}

PathInfo_obj::~PathInfo_obj() { }

Dynamic PathInfo_obj::__CreateEmpty() { return  new PathInfo_obj; }
hx::ObjectPtr< PathInfo_obj > PathInfo_obj::__new(::String path_)
{  hx::ObjectPtr< PathInfo_obj > result = new PathInfo_obj();
	result->__construct(path_);
	return result;}

Dynamic PathInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PathInfo_obj > result = new PathInfo_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PathInfo_obj::tracePaths( ){
{
		HX_STACK_PUSH("PathInfo::tracePaths","finda/PathInfo.hx",28);
		HX_STACK_THIS(this);
		HX_STACK_LINE(29)
		::haxe::Log_obj::trace((HX_CSTRING("path ") + this->path),hx::SourceInfo(HX_CSTRING("PathInfo.hx"),29,HX_CSTRING("finda.PathInfo"),HX_CSTRING("tracePaths")));
		HX_STACK_LINE(30)
		::haxe::Log_obj::trace((HX_CSTRING("full ") + this->full),hx::SourceInfo(HX_CSTRING("PathInfo.hx"),30,HX_CSTRING("finda.PathInfo"),HX_CSTRING("tracePaths")));
		HX_STACK_LINE(31)
		::haxe::Log_obj::trace((HX_CSTRING("parent ") + this->parent),hx::SourceInfo(HX_CSTRING("PathInfo.hx"),31,HX_CSTRING("finda.PathInfo"),HX_CSTRING("tracePaths")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PathInfo_obj,tracePaths,(void))

Void PathInfo_obj::changePath( ::String path_){
{
		HX_STACK_PUSH("PathInfo::changePath","finda/PathInfo.hx",16);
		HX_STACK_THIS(this);
		HX_STACK_ARG(path_,"path_");
		HX_STACK_LINE(17)
		if (((bool((this->path == path_)) && bool((this->full != null()))))){
			HX_STACK_LINE(17)
			return null();
		}
		HX_STACK_LINE(18)
		this->path = path_;
		HX_STACK_LINE(19)
		Dynamic charcode = ::StringTools_obj::fastCodeAt_dyn();		HX_STACK_VAR(charcode,"charcode");
		HX_STACK_LINE(20)
		this->full = ::sys::FileSystem_obj::fullPath(this->path);
		HX_STACK_LINE(21)
		::haxe::Log_obj::trace((HX_CSTRING(" full ") + this->full),hx::SourceInfo(HX_CSTRING("PathInfo.hx"),21,HX_CSTRING("finda.PathInfo"),HX_CSTRING("changePath")));
		HX_STACK_LINE(22)
		int len = this->full.length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(23)
		while(((bool((len > (int)0)) && bool((charcode(this->full,(len)--).Cast< int >() != (int)47))))){
		}
		HX_STACK_LINE(24)
		this->parent = (this->full.substr((int)0,(len + (int)1)) + HX_CSTRING("/"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PathInfo_obj,changePath,(void))


PathInfo_obj::PathInfo_obj()
{
}

void PathInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PathInfo);
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(full,"full");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_END_CLASS();
}

void PathInfo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(full,"full");
	HX_VISIT_MEMBER_NAME(path,"path");
}

Dynamic PathInfo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"full") ) { return full; }
		if (HX_FIELD_EQ(inName,"path") ) { return path; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tracePaths") ) { return tracePaths_dyn(); }
		if (HX_FIELD_EQ(inName,"changePath") ) { return changePath_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PathInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"full") ) { full=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PathInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("full"));
	outFields->push(HX_CSTRING("path"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("tracePaths"),
	HX_CSTRING("changePath"),
	HX_CSTRING("parent"),
	HX_CSTRING("full"),
	HX_CSTRING("path"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PathInfo_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PathInfo_obj::__mClass,"__mClass");
};

Class PathInfo_obj::__mClass;

void PathInfo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.PathInfo"), hx::TCanCast< PathInfo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PathInfo_obj::__boot()
{
}

} // end namespace finda
