// Copyright Epic Games, Inc. All Rights Reserved.
/*
 @ref      https://forums.unrealengine.com/t/how-can-i-set-avaudiosession-for-ios-apps-to-allow-device-apps-to-continue-audio-playback/130718/11
 
 IMPORTANT:     In Project Settings > Platforms - iOS > Extra PList Data > Additional Plist Data, add the following entry:
                <key>UIBackgroundModes</key><array><string>audio</string></array>
 */


#include "BackgroundAudioforIOS.h"

#if PLATFORM_IOS
#import <AVFoundation/AVFoundation.h>
#include "IOSAppDelegate.h"
#endif

#define LOCTEXT_NAMESPACE "FBackgroundAudioforIOSModule"

void FBackgroundAudioforIOSModule::StartupModule()
{
    #if PLATFORM_IOS
    
    [[IOSAppDelegate GetDelegate] SetFeature:EAudioFeature::Playback Active:true];
    [[IOSAppDelegate GetDelegate] SetFeature:EAudioFeature::BackgroundAudio Active:true];
    [[UIApplication sharedApplication] beginReceivingRemoteControlEvents];
    
    #endif
}

void FBackgroundAudioforIOSModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBackgroundAudioforIOSModule, BackgroundAudioforIOS)
