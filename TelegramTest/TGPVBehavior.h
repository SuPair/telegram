//
//  TGPVBehavior.h
//  Telegram
//
//  Created by keepcoder on 11.11.14.
//  Copyright (c) 2014 keepcoder. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TGPVBehavior <NSObject>

@property (nonatomic,strong) TL_conversation *conversation;
@property (nonatomic,strong) TGUser *user;
@property (nonatomic,assign,readonly) int totalCount;

@property (nonatomic,strong) RPCRequest *request;


typedef enum {
    TGPVMediaBehaviorLoadingStateLocal = 0,
    TGPVMediaBehaviorLoadingStateRemote = 1,
    TGPVMediaBehaviorLoadingStateFull = 2
} TGPVMediaBehaviorLoadingState;

@property (nonatomic,assign,readonly) TGPVMediaBehaviorLoadingState state;

@required
-(void)load:(long)max_id next:(BOOL)next limit:(int)limit callback:(void (^)(NSArray *))callback;
-(void)clear;
-(NSArray *)convertObjects:(NSArray *)list;


@end