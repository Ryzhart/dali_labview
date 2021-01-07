<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">true</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Vendor" Type="Folder">
			<Item Name="Dali_usb.lvlib" Type="Library" URL="../Dali_usb/Vendor/Dali_usb.lvlib"/>
			<Item Name="FTS 2p0.lvlib" Type="Library" URL="../Toolbox/Vendor/lib 2p0/FTS 2p0.lvlib"/>
		</Item>
		<Item Name="Driver_interaction.lvlib" Type="Library" URL="../Driver_interaction.lvlib"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="BuildHelpPath.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/BuildHelpPath.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="Check Special Tags.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Check Special Tags.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Close File+.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Close File+.vi"/>
				<Item Name="compatReadText.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatReadText.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Details Display Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Details Display Dialog.vi"/>
				<Item Name="DialogType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogType.ctl"/>
				<Item Name="DialogTypeEnum.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogTypeEnum.ctl"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="Error Code Database.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Code Database.vi"/>
				<Item Name="ErrWarn.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/ErrWarn.ctl"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="Find First Error.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find First Error.vi"/>
				<Item Name="Find Tag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find Tag.vi"/>
				<Item Name="Format Message String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Format Message String.vi"/>
				<Item Name="General Error Handler Core CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler Core CORE.vi"/>
				<Item Name="General Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler.vi"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="GetHelpDir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetHelpDir.vi"/>
				<Item Name="GetRTHostConnectedProp.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetRTHostConnectedProp.vi"/>
				<Item Name="LabVIEWHTTPClient.lvlib" Type="Library" URL="/&lt;vilib&gt;/httpClient/LabVIEWHTTPClient.lvlib"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="Not Found Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Not Found Dialog.vi"/>
				<Item Name="Open File+.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Open File+.vi"/>
				<Item Name="Path To Command Line String.vi" Type="VI" URL="/&lt;vilib&gt;/AdvancedString/Path To Command Line String.vi"/>
				<Item Name="PathToUNIXPathString.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/CFURL.llb/PathToUNIXPathString.vi"/>
				<Item Name="Read File+ (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read File+ (string).vi"/>
				<Item Name="Read From Spreadsheet File (DBL).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read From Spreadsheet File (DBL).vi"/>
				<Item Name="Read From Spreadsheet File (I64).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read From Spreadsheet File (I64).vi"/>
				<Item Name="Read From Spreadsheet File (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read From Spreadsheet File (string).vi"/>
				<Item Name="Read From Spreadsheet File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read From Spreadsheet File.vi"/>
				<Item Name="Read Lines From File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Lines From File.vi"/>
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Set Bold Text.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set Bold Text.vi"/>
				<Item Name="Set String Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set String Value.vi"/>
				<Item Name="TagReturnType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/TagReturnType.ctl"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Write Spreadsheet String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Spreadsheet String.vi"/>
				<Item Name="Write To Spreadsheet File (DBL).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write To Spreadsheet File (DBL).vi"/>
				<Item Name="Write To Spreadsheet File (I64).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write To Spreadsheet File (I64).vi"/>
				<Item Name="Write To Spreadsheet File (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write To Spreadsheet File (string).vi"/>
				<Item Name="Write To Spreadsheet File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write To Spreadsheet File.vi"/>
			</Item>
			<Item Name="Miscelanous.lvlibp" Type="LVLibp" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp">
				<Item Name="Controls" Type="Folder">
					<Item Name="Actions_run_service.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/Controls/Actions_run_service.ctl"/>
					<Item Name="Actions_timeout_flag.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/Controls/Actions_timeout_flag.ctl"/>
					<Item Name="Configuration_file.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/Controls/Configuration_file.ctl"/>
					<Item Name="Data_command_execute.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/Controls/Data_command_execute.ctl"/>
					<Item Name="Data_command_response.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/Controls/Data_command_response.ctl"/>
					<Item Name="Info_run_service.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/Controls/Info_run_service.ctl"/>
				</Item>
				<Item Name="SubRoutines" Type="Folder">
					<Item Name="Array_to_strings.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Array_to_strings.vi"/>
					<Item Name="Decimal_string_to_hexadecimal_string.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Decimal_string_to_hexadecimal_string.vi"/>
					<Item Name="Download_Firmware.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Download_Firmware.vi"/>
					<Item Name="Find_element_array_in_string.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Find_element_array_in_string.vi"/>
					<Item Name="Get_between_strings.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Get_between_strings.vi"/>
					<Item Name="Get_python_dictionary_values.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Get_python_dictionary_values.vi"/>
					<Item Name="Get_repo_path.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Get_repo_path.vi"/>
					<Item Name="Get_setting_filepath.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Get_setting_filepath.vi"/>
					<Item Name="Read_write_ini.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Read_write_ini.vi"/>
					<Item Name="Replace_erase_strings.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Replace_erase_strings.vi"/>
					<Item Name="Rotate message.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Rotate message.vi"/>
					<Item Name="Search_path_fw_ver.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Search_path_fw_ver.vi"/>
					<Item Name="String_to_array.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/String_to_array.vi"/>
					<Item Name="Timeout_flag.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Timeout_flag.vi"/>
					<Item Name="Wait_ms.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubRoutines/Wait_ms.vi"/>
				</Item>
				<Item Name="SubVIs" Type="Folder">
					<Item Name="Command_execute.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Command_execute.vi"/>
					<Item Name="Get_set_value_settings_file.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Get_set_value_settings_file.vi"/>
					<Item Name="Get_settings_all_values.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Get_settings_all_values.vi"/>
					<Item Name="Get_settings_all_values_by_section.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Get_settings_all_values_by_section.vi"/>
					<Item Name="Path_filter.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Path_filter.vi"/>
					<Item Name="Read_lv_ipc.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Read_lv_ipc.vi"/>
					<Item Name="Run_service.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/SubVIs/Run_service.vi"/>
				</Item>
				<Item Name="8.6CompatibleGlobalVar.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/config.llb/8.6CompatibleGlobalVar.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="Check Path.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/picture/jpeg.llb/Check Path.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Directory of Top Level VI.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/picture/jpeg.llb/Directory of Top Level VI.vi"/>
				<Item Name="Draw Flattened Pixmap.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/picture/picture.llb/Draw Flattened Pixmap.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="FixBadRect.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/picture/pictutil.llb/FixBadRect.vi"/>
				<Item Name="imagedata.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/picture/picture.llb/imagedata.ctl"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_LVConfig.lvlib" Type="Library" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/config.llb/NI_LVConfig.lvlib"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="Read JPEG File.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/picture/jpeg.llb/Read JPEG File.vi"/>
				<Item Name="Space Constant.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/dlg_ctls.llb/Space Constant.vi"/>
				<Item Name="System Exec.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Platform/system.llb/System Exec.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="../../../../Deploy/Utilities/Miscelanous.lvlibp/1abvi3w/vi.lib/Utility/error.llb/whitespace.ctl"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="Driver_interaction" Type="Packed Library">
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{8F1DF5D9-3B8A-4A00-8E7D-3D8453444003}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Driver_interaction</Property>
				<Property Name="Bld_excludeDependentPPLs" Type="Bool">true</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C/LTS/app-tde-luminaires/Deploy/Sequence/Instruments</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{5D84A0C9-1ADA-443E-9FE6-BC1D926DB49E}</Property>
				<Property Name="Bld_version.build" Type="Int">50</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Driver_interaction.lvlibp</Property>
				<Property Name="Destination[0].path" Type="Path">/C/LTS/app-tde-luminaires/Deploy/Sequence/Instruments/NI_AB_PROJECTNAME.lvlibp</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/LTS/app-tde-luminaires/Deploy/Sequence/Instruments/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="PackedLib_callersAdapt" Type="Bool">true</Property>
				<Property Name="Source[0].itemID" Type="Str">{A5172D23-C011-4E34-94B6-A13749D3AF30}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Driver_interaction.lvlib</Property>
				<Property Name="Source[1].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[1].Library.atomicCopy" Type="Bool">true</Property>
				<Property Name="Source[1].Library.LVLIBPtopLevel" Type="Bool">true</Property>
				<Property Name="Source[1].preventRename" Type="Bool">true</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">Library</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_enableDebugging" Type="Bool">true</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Driver_interaction
Created by: Ricardo Hernandez

Last modified by: Manuel Ruiz</Property>
				<Property Name="TgtF_internalName" Type="Str">Driver_interaction</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2020 </Property>
				<Property Name="TgtF_productName" Type="Str">Driver_interaction</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C10B5B6D-B59E-43E5-A998-FCEB1D671603}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Driver_interaction.lvlibp</Property>
			</Item>
		</Item>
	</Item>
</Project>
