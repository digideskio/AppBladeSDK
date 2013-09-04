//
//  AppBladeUpdates.h
//  AppBlade
//
//  Created by AndrewTremblay on 7/16/13.
//  Copyright (c) 2013 Raizlabs. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "APBBasicFeatureManager.h"
#import "AppBlade+PrivateMethods.h"

//This manager requires some UI interaction. She handles it herself.
@protocol APBUpdatesManagerDelegate <UIAlertViewDelegate>
    // Is there an update of this application available?
    -(void) appBlade:(AppBlade *)appBlade updateAvailable:(BOOL)update updateMessage:(NSString*)message updateURL:(NSString*)url;
@end

@interface APBUpdatesManager : NSObject<APBBasicFeatureManager, APBUpdatesManagerDelegate>
    @property (nonatomic, strong) id<APBWebOperationDelegate> delegate;
    @property (nonatomic, retain) NSURL* upgradeLink;

    - (void)checkForUpdates;
    - (void)handleWebClient:(APBWebOperation *)client receivedUpdate:(NSDictionary*)updateData;
    - (void)updateCallbackFailed:(APBWebOperation *)client withErrorString:(NSString*)errorString;
@end

@interface APBWebOperation (Updates)
    -(void) checkForUpdates;
@end

//Our additional requirements
@interface AppBlade (Updates)
    @property (nonatomic, strong) APBUpdatesManager* updatesManager; // we need to make the manager visible to itself.
    - (void)appBladeWebClient:(APBWebOperation *)client receivedUpdate:(NSDictionary*)updateData;
@end

