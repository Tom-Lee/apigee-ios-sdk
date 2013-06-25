//
//  ApigeeMessage.h
//  InstaOpsAppMonitor
//
//  Created by Paul Dardeau on 5/30/13.
//  Copyright (c) 2013 InstaOps. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ApigeeEntity.h"

@class ApigeeDataClient;


@interface ApigeeMessage : ApigeeEntity

@property (strong, nonatomic) NSString* category;
@property (strong, nonatomic) NSString* correlationId;
@property (strong, nonatomic) NSString* destination;
@property (strong, nonatomic) NSString* replyTo;
@property (assign, nonatomic) BOOL persistent;
@property (assign, nonatomic) BOOL indexed;

+ (BOOL)isSameType:(NSString*)type;

- (id)initWithDataClient:(ApigeeDataClient *)dataClient;
- (id)initWithEntity:(ApigeeEntity*)entity;

@end