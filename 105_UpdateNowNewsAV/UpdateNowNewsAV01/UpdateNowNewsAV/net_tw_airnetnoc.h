#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Xml.dll>
#using <System.Web.Services.dll>
#using <System.EnterpriseServices.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
// 
// 此原始程式碼由 wsdl 版本=2.0.50727.3038 自動產生。
// 
namespace net_tw_airnetnoc {
    using namespace System::Diagnostics;
    using namespace System::Web::Services;
    using namespace System::ComponentModel;
    using namespace System::Web::Services::Protocols;
    using namespace System;
    using namespace System::Xml::Serialization;
    using namespace System;
    ref class noc_Service;
    ref class GetGroupListCompletedEventArgs;
    ref class GetServiceStatusByGroupIDCompletedEventArgs;
    ref class GetServiceFailStatusByGroupIDCompletedEventArgs;
    ref class KeepaLiveCompletedEventArgs;
    ref class GetChannelEnableListCompletedEventArgs;
    ref class GetiPhoneChannelEnableListCompletedEventArgs;
    ref class GetChannnelListCompletedEventArgs;
    ref class AddChannelCompletedEventArgs;
    ref class GetGlobalChannelEnableListCompletedEventArgs;
    ref class GetGlobalChannnelListCompletedEventArgs;
    ref class AddGlobalChannelCompletedEventArgs;
    ref class DisableGlobalChannelCompletedEventArgs;
    ref class EnableGlobalChannelCompletedEventArgs;
    ref class AddGlobalChannelPicCompletedEventArgs;
    ref class GetServiceStatusByIDCompletedEventArgs;
    ref class SetServiceStatusByIDCompletedEventArgs;
    ref class SetServiceDetailByIDCompletedEventArgs;
    ref class GetServiceDetailByIDCompletedEventArgs;
    ref class FunctionTestCompletedEventArgs;
    
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetGroupListCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetGroupListCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetServiceStatusByGroupIDCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetServiceStatusByGroupIDCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetServiceFailStatusByGroupIDCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetServiceFailStatusByGroupIDCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void KeepaLiveCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::KeepaLiveCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetChannelEnableListCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetChannelEnableListCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetiPhoneChannelEnableListCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetiPhoneChannelEnableListCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetChannnelListCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetChannnelListCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void AddChannelCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::AddChannelCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetGlobalChannelEnableListCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetGlobalChannelEnableListCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetGlobalChannnelListCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetGlobalChannnelListCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void AddGlobalChannelCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::AddGlobalChannelCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void DisableGlobalChannelCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::DisableGlobalChannelCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void EnableGlobalChannelCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::EnableGlobalChannelCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void AddGlobalChannelPicCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::AddGlobalChannelPicCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetServiceStatusByIDCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetServiceStatusByIDCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void SetServiceStatusByIDCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::SetServiceStatusByIDCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void SetServiceDetailByIDCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::SetServiceDetailByIDCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void GetServiceDetailByIDCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::GetServiceDetailByIDCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038")]
    public delegate System::Void FunctionTestCompletedEventHandler(System::Object^  sender, net_tw_airnetnoc::FunctionTestCompletedEventArgs^  e);
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code"), 
    System::Web::Services::WebServiceBindingAttribute(Name=L"noc_ServiceSoap", Namespace=L"http://tempuri.org/")]
    public ref class noc_Service : public System::Web::Services::Protocols::SoapHttpClientProtocol {
        
        private: System::Threading::SendOrPostCallback^  GetGroupListOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetServiceStatusByGroupIDOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetServiceFailStatusByGroupIDOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  KeepaLiveOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetChannelEnableListOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetiPhoneChannelEnableListOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetChannnelListOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  AddChannelOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetGlobalChannelEnableListOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetGlobalChannnelListOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  AddGlobalChannelOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  DisableGlobalChannelOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  EnableGlobalChannelOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  AddGlobalChannelPicOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetServiceStatusByIDOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  SetServiceStatusByIDOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  SetServiceDetailByIDOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  GetServiceDetailByIDOperationCompleted;
        
        private: System::Threading::SendOrPostCallback^  FunctionTestOperationCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetGroupListCompletedEventHandler^  GetGroupListCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetServiceStatusByGroupIDCompletedEventHandler^  GetServiceStatusByGroupIDCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetServiceFailStatusByGroupIDCompletedEventHandler^  GetServiceFailStatusByGroupIDCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::KeepaLiveCompletedEventHandler^  KeepaLiveCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetChannelEnableListCompletedEventHandler^  GetChannelEnableListCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetiPhoneChannelEnableListCompletedEventHandler^  GetiPhoneChannelEnableListCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetChannnelListCompletedEventHandler^  GetChannnelListCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::AddChannelCompletedEventHandler^  AddChannelCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetGlobalChannelEnableListCompletedEventHandler^  GetGlobalChannelEnableListCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetGlobalChannnelListCompletedEventHandler^  GetGlobalChannnelListCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::AddGlobalChannelCompletedEventHandler^  AddGlobalChannelCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::DisableGlobalChannelCompletedEventHandler^  DisableGlobalChannelCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::EnableGlobalChannelCompletedEventHandler^  EnableGlobalChannelCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::AddGlobalChannelPicCompletedEventHandler^  AddGlobalChannelPicCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetServiceStatusByIDCompletedEventHandler^  GetServiceStatusByIDCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::SetServiceStatusByIDCompletedEventHandler^  SetServiceStatusByIDCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::SetServiceDetailByIDCompletedEventHandler^  SetServiceDetailByIDCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::GetServiceDetailByIDCompletedEventHandler^  GetServiceDetailByIDCompleted;
        
        /// <remarks/>
        public: event net_tw_airnetnoc::FunctionTestCompletedEventHandler^  FunctionTestCompleted;
        
        /// <remarks/>
        public: noc_Service();
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetGroupList", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetGroupList();
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetGroupList(System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetGroupList(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetGroupListAsync();
        
        /// <remarks/>
        public: System::Void GetGroupListAsync(System::Object^  userState);
        
        private: System::Void OnGetGroupListOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetServiceStatusByGroupID", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetServiceStatusByGroupID(System::Int32 GroupID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetServiceStatusByGroupID(System::Int32 GroupID, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetServiceStatusByGroupID(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetServiceStatusByGroupIDAsync(System::Int32 GroupID);
        
        /// <remarks/>
        public: System::Void GetServiceStatusByGroupIDAsync(System::Int32 GroupID, System::Object^  userState);
        
        private: System::Void OnGetServiceStatusByGroupIDOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetServiceFailStatusByGroupID", 
            RequestNamespace=L"http://tempuri.org/", ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, 
            ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetServiceFailStatusByGroupID(System::Int32 GroupID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetServiceFailStatusByGroupID(System::Int32 GroupID, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetServiceFailStatusByGroupID(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetServiceFailStatusByGroupIDAsync(System::Int32 GroupID);
        
        /// <remarks/>
        public: System::Void GetServiceFailStatusByGroupIDAsync(System::Int32 GroupID, System::Object^  userState);
        
        private: System::Void OnGetServiceFailStatusByGroupIDOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/KeepaLive", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  KeepaLive(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginKeepaLive(System::Int32 ServiceID, System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndKeepaLive(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void KeepaLiveAsync(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::Void KeepaLiveAsync(System::Int32 ServiceID, System::Object^  userState);
        
        private: System::Void OnKeepaLiveOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetChannelEnableList", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetChannelEnableList();
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetChannelEnableList(System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetChannelEnableList(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetChannelEnableListAsync();
        
        /// <remarks/>
        public: System::Void GetChannelEnableListAsync(System::Object^  userState);
        
        private: System::Void OnGetChannelEnableListOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetiPhoneChannelEnableList", 
            RequestNamespace=L"http://tempuri.org/", ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, 
            ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetiPhoneChannelEnableList();
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetiPhoneChannelEnableList(System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetiPhoneChannelEnableList(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetiPhoneChannelEnableListAsync();
        
        /// <remarks/>
        public: System::Void GetiPhoneChannelEnableListAsync(System::Object^  userState);
        
        private: System::Void OnGetiPhoneChannelEnableListOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetChannnelList", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetChannnelList();
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetChannnelList(System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetChannnelList(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetChannnelListAsync();
        
        /// <remarks/>
        public: System::Void GetChannnelListAsync(System::Object^  userState);
        
        private: System::Void OnGetChannnelListOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/AddChannel", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  AddChannel(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginAddChannel(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag, 
                    System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndAddChannel(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void AddChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag);
        
        /// <remarks/>
        public: System::Void AddChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag, 
                    System::Object^  userState);
        
        private: System::Void OnAddChannelOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetGlobalChannelEnableList", 
            RequestNamespace=L"http://tempuri.org/", ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, 
            ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetGlobalChannelEnableList();
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetGlobalChannelEnableList(System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetGlobalChannelEnableList(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetGlobalChannelEnableListAsync();
        
        /// <remarks/>
        public: System::Void GetGlobalChannelEnableListAsync(System::Object^  userState);
        
        private: System::Void OnGetGlobalChannelEnableListOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetGlobalChannnelList", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetGlobalChannnelList();
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetGlobalChannnelList(System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetGlobalChannnelList(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetGlobalChannnelListAsync();
        
        /// <remarks/>
        public: System::Void GetGlobalChannnelListAsync(System::Object^  userState);
        
        private: System::Void OnGetGlobalChannnelListOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/AddGlobalChannel", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  AddGlobalChannel(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginAddGlobalChannel(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag, 
                    System::AsyncCallback^  callback, System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndAddGlobalChannel(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void AddGlobalChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag);
        
        /// <remarks/>
        public: System::Void AddGlobalChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag, 
                    System::Object^  userState);
        
        private: System::Void OnAddGlobalChannelOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/DisableGlobalChannel", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  DisableGlobalChannel(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginDisableGlobalChannel(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndDisableGlobalChannel(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void DisableGlobalChannelAsync(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::Void DisableGlobalChannelAsync(System::Int32 ServiceID, System::Object^  userState);
        
        private: System::Void OnDisableGlobalChannelOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/EnableGlobalChannel", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  EnableGlobalChannel(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginEnableGlobalChannel(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndEnableGlobalChannel(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void EnableGlobalChannelAsync(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::Void EnableGlobalChannelAsync(System::Int32 ServiceID, System::Object^  userState);
        
        private: System::Void OnEnableGlobalChannelOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/AddGlobalChannelPic", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::Boolean AddGlobalChannelPic(System::Int32 ServiceID, System::String^  ImgPath);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginAddGlobalChannelPic(System::Int32 ServiceID, System::String^  ImgPath, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::Boolean EndAddGlobalChannelPic(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void AddGlobalChannelPicAsync(System::Int32 ServiceID, System::String^  ImgPath);
        
        /// <remarks/>
        public: System::Void AddGlobalChannelPicAsync(System::Int32 ServiceID, System::String^  ImgPath, System::Object^  userState);
        
        private: System::Void OnAddGlobalChannelPicOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetServiceStatusByID", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetServiceStatusByID(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetServiceStatusByID(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetServiceStatusByID(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetServiceStatusByIDAsync(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::Void GetServiceStatusByIDAsync(System::Int32 ServiceID, System::Object^  userState);
        
        private: System::Void OnGetServiceStatusByIDOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/SetServiceStatusByID", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  SetServiceStatusByID(System::Int32 ServiceID, System::Int32 Status, System::Double Current_Value, 
                    System::String^  Service_Memo);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginSetServiceStatusByID(
                    System::Int32 ServiceID, 
                    System::Int32 Status, 
                    System::Double Current_Value, 
                    System::String^  Service_Memo, 
                    System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndSetServiceStatusByID(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void SetServiceStatusByIDAsync(System::Int32 ServiceID, System::Int32 Status, System::Double Current_Value, 
                    System::String^  Service_Memo);
        
        /// <remarks/>
        public: System::Void SetServiceStatusByIDAsync(System::Int32 ServiceID, System::Int32 Status, System::Double Current_Value, 
                    System::String^  Service_Memo, System::Object^  userState);
        
        private: System::Void OnSetServiceStatusByIDOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/SetServiceDetailByID", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  SetServiceDetailByID(System::Int32 Service_ID, System::String^  DetailXML);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginSetServiceDetailByID(System::Int32 Service_ID, System::String^  DetailXML, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndSetServiceDetailByID(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void SetServiceDetailByIDAsync(System::Int32 Service_ID, System::String^  DetailXML);
        
        /// <remarks/>
        public: System::Void SetServiceDetailByIDAsync(System::Int32 Service_ID, System::String^  DetailXML, System::Object^  userState);
        
        private: System::Void OnSetServiceDetailByIDOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/GetServiceDetailByID", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  GetServiceDetailByID(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginGetServiceDetailByID(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndGetServiceDetailByID(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void GetServiceDetailByIDAsync(System::Int32 ServiceID);
        
        /// <remarks/>
        public: System::Void GetServiceDetailByIDAsync(System::Int32 ServiceID, System::Object^  userState);
        
        private: System::Void OnGetServiceDetailByIDOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: [System::Web::Services::Protocols::SoapDocumentMethodAttribute(L"http://tempuri.org/FunctionTest", RequestNamespace=L"http://tempuri.org/", 
            ResponseNamespace=L"http://tempuri.org/", Use=System::Web::Services::Description::SoapBindingUse::Literal, ParameterStyle=System::Web::Services::Protocols::SoapParameterStyle::Wrapped)]
        System::String^  FunctionTest(System::Int32 intParam, System::String^  strParam);
        
        /// <remarks/>
        public: System::IAsyncResult^  BeginFunctionTest(System::Int32 intParam, System::String^  strParam, System::AsyncCallback^  callback, 
                    System::Object^  asyncState);
        
        /// <remarks/>
        public: System::String^  EndFunctionTest(System::IAsyncResult^  asyncResult);
        
        /// <remarks/>
        public: System::Void FunctionTestAsync(System::Int32 intParam, System::String^  strParam);
        
        /// <remarks/>
        public: System::Void FunctionTestAsync(System::Int32 intParam, System::String^  strParam, System::Object^  userState);
        
        private: System::Void OnFunctionTestOperationCompleted(System::Object^  arg);
        
        /// <remarks/>
        public: System::Void CancelAsync(System::Object^  userState) new;
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetGroupListCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetGroupListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetServiceStatusByGroupIDCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetServiceStatusByGroupIDCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetServiceFailStatusByGroupIDCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetServiceFailStatusByGroupIDCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class KeepaLiveCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: KeepaLiveCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, System::Boolean cancelled, 
                    System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetChannelEnableListCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetChannelEnableListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetiPhoneChannelEnableListCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetiPhoneChannelEnableListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetChannnelListCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetChannnelListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class AddChannelCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: AddChannelCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, System::Boolean cancelled, 
                    System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetGlobalChannelEnableListCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetGlobalChannelEnableListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetGlobalChannnelListCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetGlobalChannnelListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class AddGlobalChannelCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: AddGlobalChannelCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class DisableGlobalChannelCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: DisableGlobalChannelCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class EnableGlobalChannelCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: EnableGlobalChannelCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class AddGlobalChannelPicCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: AddGlobalChannelPicCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::Boolean Result {
            System::Boolean get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetServiceStatusByIDCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetServiceStatusByIDCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class SetServiceStatusByIDCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: SetServiceStatusByIDCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class SetServiceDetailByIDCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: SetServiceDetailByIDCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class GetServiceDetailByIDCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: GetServiceDetailByIDCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
    
    /// <remarks/>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"wsdl", L"2.0.50727.3038"), 
    System::Diagnostics::DebuggerStepThroughAttribute, 
    System::ComponentModel::DesignerCategoryAttribute(L"code")]
    public ref class FunctionTestCompletedEventArgs : public System::ComponentModel::AsyncCompletedEventArgs {
        
        private: cli::array< System::Object^  >^  results;
        
        internal: FunctionTestCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                    System::Boolean cancelled, System::Object^  userState);
        /// <remarks/>
        public: property System::String^  Result {
            System::String^  get();
        }
    };
}
namespace net_tw_airnetnoc {
    
    
    inline noc_Service::noc_Service() {
        this->Url = L"http://noc.tw-airnet.net/monitor/noc_service.asmx";
    }
    
    inline System::String^  noc_Service::GetGroupList() {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetGroupList", gcnew cli::array< System::Object^  >(0));
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetGroupList(System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"GetGroupList", gcnew cli::array< System::Object^  >(0), callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetGroupList(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetGroupListAsync() {
        this->GetGroupListAsync(nullptr);
    }
    
    inline System::Void noc_Service::GetGroupListAsync(System::Object^  userState) {
        if (this->GetGroupListOperationCompleted == nullptr) {
            this->GetGroupListOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetGroupListOperationCompleted);
        }
        this->InvokeAsync(L"GetGroupList", gcnew cli::array< System::Object^  >(0), this->GetGroupListOperationCompleted, userState);
    }
    
    inline System::Void noc_Service::OnGetGroupListOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetGroupListCompleted(this, (gcnew net_tw_airnetnoc::GetGroupListCompletedEventArgs(invokeArgs->Results, invokeArgs->Error, 
                    invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetServiceStatusByGroupID(System::Int32 GroupID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetServiceStatusByGroupID", gcnew cli::array< System::Object^  >(1) {GroupID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetServiceStatusByGroupID(System::Int32 GroupID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"GetServiceStatusByGroupID", gcnew cli::array< System::Object^  >(1) {GroupID}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetServiceStatusByGroupID(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetServiceStatusByGroupIDAsync(System::Int32 GroupID) {
        this->GetServiceStatusByGroupIDAsync(GroupID, nullptr);
    }
    
    inline System::Void noc_Service::GetServiceStatusByGroupIDAsync(System::Int32 GroupID, System::Object^  userState) {
        if (this->GetServiceStatusByGroupIDOperationCompleted == nullptr) {
            this->GetServiceStatusByGroupIDOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetServiceStatusByGroupIDOperationCompleted);
        }
        this->InvokeAsync(L"GetServiceStatusByGroupID", gcnew cli::array< System::Object^  >(1) {GroupID}, this->GetServiceStatusByGroupIDOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetServiceStatusByGroupIDOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetServiceStatusByGroupIDCompleted(this, (gcnew net_tw_airnetnoc::GetServiceStatusByGroupIDCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetServiceFailStatusByGroupID(System::Int32 GroupID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetServiceFailStatusByGroupID", gcnew cli::array< System::Object^  >(1) {GroupID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetServiceFailStatusByGroupID(System::Int32 GroupID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"GetServiceFailStatusByGroupID", gcnew cli::array< System::Object^  >(1) {GroupID}, callback, 
            asyncState);
    }
    
    inline System::String^  noc_Service::EndGetServiceFailStatusByGroupID(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetServiceFailStatusByGroupIDAsync(System::Int32 GroupID) {
        this->GetServiceFailStatusByGroupIDAsync(GroupID, nullptr);
    }
    
    inline System::Void noc_Service::GetServiceFailStatusByGroupIDAsync(System::Int32 GroupID, System::Object^  userState) {
        if (this->GetServiceFailStatusByGroupIDOperationCompleted == nullptr) {
            this->GetServiceFailStatusByGroupIDOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetServiceFailStatusByGroupIDOperationCompleted);
        }
        this->InvokeAsync(L"GetServiceFailStatusByGroupID", gcnew cli::array< System::Object^  >(1) {GroupID}, this->GetServiceFailStatusByGroupIDOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetServiceFailStatusByGroupIDOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetServiceFailStatusByGroupIDCompleted(this, (gcnew net_tw_airnetnoc::GetServiceFailStatusByGroupIDCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::KeepaLive(System::Int32 ServiceID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"KeepaLive", gcnew cli::array< System::Object^  >(1) {ServiceID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginKeepaLive(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"KeepaLive", gcnew cli::array< System::Object^  >(1) {ServiceID}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndKeepaLive(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::KeepaLiveAsync(System::Int32 ServiceID) {
        this->KeepaLiveAsync(ServiceID, nullptr);
    }
    
    inline System::Void noc_Service::KeepaLiveAsync(System::Int32 ServiceID, System::Object^  userState) {
        if (this->KeepaLiveOperationCompleted == nullptr) {
            this->KeepaLiveOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnKeepaLiveOperationCompleted);
        }
        this->InvokeAsync(L"KeepaLive", gcnew cli::array< System::Object^  >(1) {ServiceID}, this->KeepaLiveOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnKeepaLiveOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->KeepaLiveCompleted(this, (gcnew net_tw_airnetnoc::KeepaLiveCompletedEventArgs(invokeArgs->Results, invokeArgs->Error, 
                    invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetChannelEnableList() {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetChannelEnableList", gcnew cli::array< System::Object^  >(0));
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetChannelEnableList(System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"GetChannelEnableList", gcnew cli::array< System::Object^  >(0), callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetChannelEnableList(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetChannelEnableListAsync() {
        this->GetChannelEnableListAsync(nullptr);
    }
    
    inline System::Void noc_Service::GetChannelEnableListAsync(System::Object^  userState) {
        if (this->GetChannelEnableListOperationCompleted == nullptr) {
            this->GetChannelEnableListOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetChannelEnableListOperationCompleted);
        }
        this->InvokeAsync(L"GetChannelEnableList", gcnew cli::array< System::Object^  >(0), this->GetChannelEnableListOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetChannelEnableListOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetChannelEnableListCompleted(this, (gcnew net_tw_airnetnoc::GetChannelEnableListCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetiPhoneChannelEnableList() {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetiPhoneChannelEnableList", gcnew cli::array< System::Object^  >(0));
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetiPhoneChannelEnableList(System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"GetiPhoneChannelEnableList", gcnew cli::array< System::Object^  >(0), callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetiPhoneChannelEnableList(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetiPhoneChannelEnableListAsync() {
        this->GetiPhoneChannelEnableListAsync(nullptr);
    }
    
    inline System::Void noc_Service::GetiPhoneChannelEnableListAsync(System::Object^  userState) {
        if (this->GetiPhoneChannelEnableListOperationCompleted == nullptr) {
            this->GetiPhoneChannelEnableListOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetiPhoneChannelEnableListOperationCompleted);
        }
        this->InvokeAsync(L"GetiPhoneChannelEnableList", gcnew cli::array< System::Object^  >(0), this->GetiPhoneChannelEnableListOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetiPhoneChannelEnableListOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetiPhoneChannelEnableListCompleted(this, (gcnew net_tw_airnetnoc::GetiPhoneChannelEnableListCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetChannnelList() {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetChannnelList", gcnew cli::array< System::Object^  >(0));
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetChannnelList(System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"GetChannnelList", gcnew cli::array< System::Object^  >(0), callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetChannnelList(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetChannnelListAsync() {
        this->GetChannnelListAsync(nullptr);
    }
    
    inline System::Void noc_Service::GetChannnelListAsync(System::Object^  userState) {
        if (this->GetChannnelListOperationCompleted == nullptr) {
            this->GetChannnelListOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetChannnelListOperationCompleted);
        }
        this->InvokeAsync(L"GetChannnelList", gcnew cli::array< System::Object^  >(0), this->GetChannnelListOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetChannnelListOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetChannnelListCompleted(this, (gcnew net_tw_airnetnoc::GetChannnelListCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::AddChannel(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag) {
        cli::array< System::Object^  >^  results = this->Invoke(L"AddChannel", gcnew cli::array< System::Object^  >(3) {ChannelName, 
                ChannelUrl, EnableFlag});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginAddChannel(System::String^  ChannelName, System::String^  ChannelUrl, 
                System::Int32 EnableFlag, System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"AddChannel", gcnew cli::array< System::Object^  >(3) {ChannelName, ChannelUrl, EnableFlag}, 
            callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndAddChannel(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::AddChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag) {
        this->AddChannelAsync(ChannelName, ChannelUrl, EnableFlag, nullptr);
    }
    
    inline System::Void noc_Service::AddChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag, 
                System::Object^  userState) {
        if (this->AddChannelOperationCompleted == nullptr) {
            this->AddChannelOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnAddChannelOperationCompleted);
        }
        this->InvokeAsync(L"AddChannel", gcnew cli::array< System::Object^  >(3) {ChannelName, ChannelUrl, EnableFlag}, this->AddChannelOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnAddChannelOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->AddChannelCompleted(this, (gcnew net_tw_airnetnoc::AddChannelCompletedEventArgs(invokeArgs->Results, invokeArgs->Error, 
                    invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetGlobalChannelEnableList() {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetGlobalChannelEnableList", gcnew cli::array< System::Object^  >(0));
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetGlobalChannelEnableList(System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"GetGlobalChannelEnableList", gcnew cli::array< System::Object^  >(0), callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetGlobalChannelEnableList(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetGlobalChannelEnableListAsync() {
        this->GetGlobalChannelEnableListAsync(nullptr);
    }
    
    inline System::Void noc_Service::GetGlobalChannelEnableListAsync(System::Object^  userState) {
        if (this->GetGlobalChannelEnableListOperationCompleted == nullptr) {
            this->GetGlobalChannelEnableListOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetGlobalChannelEnableListOperationCompleted);
        }
        this->InvokeAsync(L"GetGlobalChannelEnableList", gcnew cli::array< System::Object^  >(0), this->GetGlobalChannelEnableListOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetGlobalChannelEnableListOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetGlobalChannelEnableListCompleted(this, (gcnew net_tw_airnetnoc::GetGlobalChannelEnableListCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetGlobalChannnelList() {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetGlobalChannnelList", gcnew cli::array< System::Object^  >(0));
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetGlobalChannnelList(System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"GetGlobalChannnelList", gcnew cli::array< System::Object^  >(0), callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetGlobalChannnelList(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetGlobalChannnelListAsync() {
        this->GetGlobalChannnelListAsync(nullptr);
    }
    
    inline System::Void noc_Service::GetGlobalChannnelListAsync(System::Object^  userState) {
        if (this->GetGlobalChannnelListOperationCompleted == nullptr) {
            this->GetGlobalChannnelListOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetGlobalChannnelListOperationCompleted);
        }
        this->InvokeAsync(L"GetGlobalChannnelList", gcnew cli::array< System::Object^  >(0), this->GetGlobalChannnelListOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetGlobalChannnelListOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetGlobalChannnelListCompleted(this, (gcnew net_tw_airnetnoc::GetGlobalChannnelListCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::AddGlobalChannel(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag) {
        cli::array< System::Object^  >^  results = this->Invoke(L"AddGlobalChannel", gcnew cli::array< System::Object^  >(3) {ChannelName, 
                ChannelUrl, EnableFlag});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginAddGlobalChannel(System::String^  ChannelName, System::String^  ChannelUrl, 
                System::Int32 EnableFlag, System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"AddGlobalChannel", gcnew cli::array< System::Object^  >(3) {ChannelName, ChannelUrl, EnableFlag}, 
            callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndAddGlobalChannel(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::AddGlobalChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag) {
        this->AddGlobalChannelAsync(ChannelName, ChannelUrl, EnableFlag, nullptr);
    }
    
    inline System::Void noc_Service::AddGlobalChannelAsync(System::String^  ChannelName, System::String^  ChannelUrl, System::Int32 EnableFlag, 
                System::Object^  userState) {
        if (this->AddGlobalChannelOperationCompleted == nullptr) {
            this->AddGlobalChannelOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnAddGlobalChannelOperationCompleted);
        }
        this->InvokeAsync(L"AddGlobalChannel", gcnew cli::array< System::Object^  >(3) {ChannelName, ChannelUrl, EnableFlag}, 
            this->AddGlobalChannelOperationCompleted, userState);
    }
    
    inline System::Void noc_Service::OnAddGlobalChannelOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->AddGlobalChannelCompleted(this, (gcnew net_tw_airnetnoc::AddGlobalChannelCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::DisableGlobalChannel(System::Int32 ServiceID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"DisableGlobalChannel", gcnew cli::array< System::Object^  >(1) {ServiceID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginDisableGlobalChannel(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"DisableGlobalChannel", gcnew cli::array< System::Object^  >(1) {ServiceID}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndDisableGlobalChannel(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::DisableGlobalChannelAsync(System::Int32 ServiceID) {
        this->DisableGlobalChannelAsync(ServiceID, nullptr);
    }
    
    inline System::Void noc_Service::DisableGlobalChannelAsync(System::Int32 ServiceID, System::Object^  userState) {
        if (this->DisableGlobalChannelOperationCompleted == nullptr) {
            this->DisableGlobalChannelOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnDisableGlobalChannelOperationCompleted);
        }
        this->InvokeAsync(L"DisableGlobalChannel", gcnew cli::array< System::Object^  >(1) {ServiceID}, this->DisableGlobalChannelOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnDisableGlobalChannelOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->DisableGlobalChannelCompleted(this, (gcnew net_tw_airnetnoc::DisableGlobalChannelCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::EnableGlobalChannel(System::Int32 ServiceID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"EnableGlobalChannel", gcnew cli::array< System::Object^  >(1) {ServiceID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginEnableGlobalChannel(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"EnableGlobalChannel", gcnew cli::array< System::Object^  >(1) {ServiceID}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndEnableGlobalChannel(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::EnableGlobalChannelAsync(System::Int32 ServiceID) {
        this->EnableGlobalChannelAsync(ServiceID, nullptr);
    }
    
    inline System::Void noc_Service::EnableGlobalChannelAsync(System::Int32 ServiceID, System::Object^  userState) {
        if (this->EnableGlobalChannelOperationCompleted == nullptr) {
            this->EnableGlobalChannelOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnEnableGlobalChannelOperationCompleted);
        }
        this->InvokeAsync(L"EnableGlobalChannel", gcnew cli::array< System::Object^  >(1) {ServiceID}, this->EnableGlobalChannelOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnEnableGlobalChannelOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->EnableGlobalChannelCompleted(this, (gcnew net_tw_airnetnoc::EnableGlobalChannelCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::Boolean noc_Service::AddGlobalChannelPic(System::Int32 ServiceID, System::String^  ImgPath) {
        cli::array< System::Object^  >^  results = this->Invoke(L"AddGlobalChannelPic", gcnew cli::array< System::Object^  >(2) {ServiceID, 
                ImgPath});
        return (cli::safe_cast<System::Boolean >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginAddGlobalChannelPic(System::Int32 ServiceID, System::String^  ImgPath, 
                System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"AddGlobalChannelPic", gcnew cli::array< System::Object^  >(2) {ServiceID, ImgPath}, callback, 
            asyncState);
    }
    
    inline System::Boolean noc_Service::EndAddGlobalChannelPic(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::Boolean >(results[0]));
    }
    
    inline System::Void noc_Service::AddGlobalChannelPicAsync(System::Int32 ServiceID, System::String^  ImgPath) {
        this->AddGlobalChannelPicAsync(ServiceID, ImgPath, nullptr);
    }
    
    inline System::Void noc_Service::AddGlobalChannelPicAsync(System::Int32 ServiceID, System::String^  ImgPath, System::Object^  userState) {
        if (this->AddGlobalChannelPicOperationCompleted == nullptr) {
            this->AddGlobalChannelPicOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnAddGlobalChannelPicOperationCompleted);
        }
        this->InvokeAsync(L"AddGlobalChannelPic", gcnew cli::array< System::Object^  >(2) {ServiceID, ImgPath}, this->AddGlobalChannelPicOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnAddGlobalChannelPicOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->AddGlobalChannelPicCompleted(this, (gcnew net_tw_airnetnoc::AddGlobalChannelPicCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetServiceStatusByID(System::Int32 ServiceID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetServiceStatusByID", gcnew cli::array< System::Object^  >(1) {ServiceID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetServiceStatusByID(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"GetServiceStatusByID", gcnew cli::array< System::Object^  >(1) {ServiceID}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetServiceStatusByID(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetServiceStatusByIDAsync(System::Int32 ServiceID) {
        this->GetServiceStatusByIDAsync(ServiceID, nullptr);
    }
    
    inline System::Void noc_Service::GetServiceStatusByIDAsync(System::Int32 ServiceID, System::Object^  userState) {
        if (this->GetServiceStatusByIDOperationCompleted == nullptr) {
            this->GetServiceStatusByIDOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetServiceStatusByIDOperationCompleted);
        }
        this->InvokeAsync(L"GetServiceStatusByID", gcnew cli::array< System::Object^  >(1) {ServiceID}, this->GetServiceStatusByIDOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetServiceStatusByIDOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetServiceStatusByIDCompleted(this, (gcnew net_tw_airnetnoc::GetServiceStatusByIDCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::SetServiceStatusByID(System::Int32 ServiceID, System::Int32 Status, System::Double Current_Value, 
                System::String^  Service_Memo) {
        cli::array< System::Object^  >^  results = this->Invoke(L"SetServiceStatusByID", gcnew cli::array< System::Object^  >(4) {ServiceID, 
                Status, Current_Value, Service_Memo});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginSetServiceStatusByID(
                System::Int32 ServiceID, 
                System::Int32 Status, 
                System::Double Current_Value, 
                System::String^  Service_Memo, 
                System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"SetServiceStatusByID", gcnew cli::array< System::Object^  >(4) {ServiceID, Status, Current_Value, 
                Service_Memo}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndSetServiceStatusByID(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::SetServiceStatusByIDAsync(System::Int32 ServiceID, System::Int32 Status, System::Double Current_Value, 
                System::String^  Service_Memo) {
        this->SetServiceStatusByIDAsync(ServiceID, Status, Current_Value, Service_Memo, nullptr);
    }
    
    inline System::Void noc_Service::SetServiceStatusByIDAsync(System::Int32 ServiceID, System::Int32 Status, System::Double Current_Value, 
                System::String^  Service_Memo, System::Object^  userState) {
        if (this->SetServiceStatusByIDOperationCompleted == nullptr) {
            this->SetServiceStatusByIDOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnSetServiceStatusByIDOperationCompleted);
        }
        this->InvokeAsync(L"SetServiceStatusByID", gcnew cli::array< System::Object^  >(4) {ServiceID, Status, Current_Value, 
                Service_Memo}, this->SetServiceStatusByIDOperationCompleted, userState);
    }
    
    inline System::Void noc_Service::OnSetServiceStatusByIDOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->SetServiceStatusByIDCompleted(this, (gcnew net_tw_airnetnoc::SetServiceStatusByIDCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::SetServiceDetailByID(System::Int32 Service_ID, System::String^  DetailXML) {
        cli::array< System::Object^  >^  results = this->Invoke(L"SetServiceDetailByID", gcnew cli::array< System::Object^  >(2) {Service_ID, 
                DetailXML});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginSetServiceDetailByID(System::Int32 Service_ID, System::String^  DetailXML, 
                System::AsyncCallback^  callback, System::Object^  asyncState) {
        return this->BeginInvoke(L"SetServiceDetailByID", gcnew cli::array< System::Object^  >(2) {Service_ID, DetailXML}, callback, 
            asyncState);
    }
    
    inline System::String^  noc_Service::EndSetServiceDetailByID(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::SetServiceDetailByIDAsync(System::Int32 Service_ID, System::String^  DetailXML) {
        this->SetServiceDetailByIDAsync(Service_ID, DetailXML, nullptr);
    }
    
    inline System::Void noc_Service::SetServiceDetailByIDAsync(System::Int32 Service_ID, System::String^  DetailXML, System::Object^  userState) {
        if (this->SetServiceDetailByIDOperationCompleted == nullptr) {
            this->SetServiceDetailByIDOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnSetServiceDetailByIDOperationCompleted);
        }
        this->InvokeAsync(L"SetServiceDetailByID", gcnew cli::array< System::Object^  >(2) {Service_ID, DetailXML}, this->SetServiceDetailByIDOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnSetServiceDetailByIDOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->SetServiceDetailByIDCompleted(this, (gcnew net_tw_airnetnoc::SetServiceDetailByIDCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::GetServiceDetailByID(System::Int32 ServiceID) {
        cli::array< System::Object^  >^  results = this->Invoke(L"GetServiceDetailByID", gcnew cli::array< System::Object^  >(1) {ServiceID});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginGetServiceDetailByID(System::Int32 ServiceID, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"GetServiceDetailByID", gcnew cli::array< System::Object^  >(1) {ServiceID}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndGetServiceDetailByID(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::GetServiceDetailByIDAsync(System::Int32 ServiceID) {
        this->GetServiceDetailByIDAsync(ServiceID, nullptr);
    }
    
    inline System::Void noc_Service::GetServiceDetailByIDAsync(System::Int32 ServiceID, System::Object^  userState) {
        if (this->GetServiceDetailByIDOperationCompleted == nullptr) {
            this->GetServiceDetailByIDOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnGetServiceDetailByIDOperationCompleted);
        }
        this->InvokeAsync(L"GetServiceDetailByID", gcnew cli::array< System::Object^  >(1) {ServiceID}, this->GetServiceDetailByIDOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnGetServiceDetailByIDOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->GetServiceDetailByIDCompleted(this, (gcnew net_tw_airnetnoc::GetServiceDetailByIDCompletedEventArgs(invokeArgs->Results, 
                    invokeArgs->Error, invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::String^  noc_Service::FunctionTest(System::Int32 intParam, System::String^  strParam) {
        cli::array< System::Object^  >^  results = this->Invoke(L"FunctionTest", gcnew cli::array< System::Object^  >(2) {intParam, 
                strParam});
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::IAsyncResult^  noc_Service::BeginFunctionTest(System::Int32 intParam, System::String^  strParam, System::AsyncCallback^  callback, 
                System::Object^  asyncState) {
        return this->BeginInvoke(L"FunctionTest", gcnew cli::array< System::Object^  >(2) {intParam, strParam}, callback, asyncState);
    }
    
    inline System::String^  noc_Service::EndFunctionTest(System::IAsyncResult^  asyncResult) {
        cli::array< System::Object^  >^  results = this->EndInvoke(asyncResult);
        return (cli::safe_cast<System::String^  >(results[0]));
    }
    
    inline System::Void noc_Service::FunctionTestAsync(System::Int32 intParam, System::String^  strParam) {
        this->FunctionTestAsync(intParam, strParam, nullptr);
    }
    
    inline System::Void noc_Service::FunctionTestAsync(System::Int32 intParam, System::String^  strParam, System::Object^  userState) {
        if (this->FunctionTestOperationCompleted == nullptr) {
            this->FunctionTestOperationCompleted = gcnew System::Threading::SendOrPostCallback(this, &net_tw_airnetnoc::noc_Service::OnFunctionTestOperationCompleted);
        }
        this->InvokeAsync(L"FunctionTest", gcnew cli::array< System::Object^  >(2) {intParam, strParam}, this->FunctionTestOperationCompleted, 
            userState);
    }
    
    inline System::Void noc_Service::OnFunctionTestOperationCompleted(System::Object^  arg) {
        {
            System::Web::Services::Protocols::InvokeCompletedEventArgs^  invokeArgs = (cli::safe_cast<System::Web::Services::Protocols::InvokeCompletedEventArgs^  >(arg));
            this->FunctionTestCompleted(this, (gcnew net_tw_airnetnoc::FunctionTestCompletedEventArgs(invokeArgs->Results, invokeArgs->Error, 
                    invokeArgs->Cancelled, invokeArgs->UserState)));
        }
    }
    
    inline System::Void noc_Service::CancelAsync(System::Object^  userState) {
        __super::CancelAsync(userState);
    }
    
    
    inline GetGroupListCompletedEventArgs::GetGroupListCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetGroupListCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetServiceStatusByGroupIDCompletedEventArgs::GetServiceStatusByGroupIDCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetServiceStatusByGroupIDCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetServiceFailStatusByGroupIDCompletedEventArgs::GetServiceFailStatusByGroupIDCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetServiceFailStatusByGroupIDCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline KeepaLiveCompletedEventArgs::KeepaLiveCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  KeepaLiveCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetChannelEnableListCompletedEventArgs::GetChannelEnableListCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetChannelEnableListCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetiPhoneChannelEnableListCompletedEventArgs::GetiPhoneChannelEnableListCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetiPhoneChannelEnableListCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetChannnelListCompletedEventArgs::GetChannnelListCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetChannnelListCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline AddChannelCompletedEventArgs::AddChannelCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  AddChannelCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetGlobalChannelEnableListCompletedEventArgs::GetGlobalChannelEnableListCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetGlobalChannelEnableListCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetGlobalChannnelListCompletedEventArgs::GetGlobalChannnelListCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetGlobalChannnelListCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline AddGlobalChannelCompletedEventArgs::AddGlobalChannelCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  AddGlobalChannelCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline DisableGlobalChannelCompletedEventArgs::DisableGlobalChannelCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  DisableGlobalChannelCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline EnableGlobalChannelCompletedEventArgs::EnableGlobalChannelCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  EnableGlobalChannelCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline AddGlobalChannelPicCompletedEventArgs::AddGlobalChannelPicCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::Boolean AddGlobalChannelPicCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::Boolean >(this->results[0]));
    }
    
    
    inline GetServiceStatusByIDCompletedEventArgs::GetServiceStatusByIDCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetServiceStatusByIDCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline SetServiceStatusByIDCompletedEventArgs::SetServiceStatusByIDCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  SetServiceStatusByIDCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline SetServiceDetailByIDCompletedEventArgs::SetServiceDetailByIDCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  SetServiceDetailByIDCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline GetServiceDetailByIDCompletedEventArgs::GetServiceDetailByIDCompletedEventArgs(cli::array< System::Object^  >^  results, 
                System::Exception^  exception, System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  GetServiceDetailByIDCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
    
    
    inline FunctionTestCompletedEventArgs::FunctionTestCompletedEventArgs(cli::array< System::Object^  >^  results, System::Exception^  exception, 
                System::Boolean cancelled, System::Object^  userState) : 
            System::ComponentModel::AsyncCompletedEventArgs(exception, cancelled, userState) {
        this->results = results;
    }
    
    inline System::String^  FunctionTestCompletedEventArgs::Result::get() {
        this->RaiseExceptionIfNecessary();
        return (cli::safe_cast<System::String^  >(this->results[0]));
    }
}
