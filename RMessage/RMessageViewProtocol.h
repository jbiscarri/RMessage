//
//  RMessageViewProtocol.h
//  RMessage
//
//  Created by Adonis Peralta on 3/23/17.
//  Copyright © 2017 Adonis Peralta. All rights reserved.
//

@protocol RMessageViewProtocol <NSObject>

@optional
- (void)messageViewIsPresenting:(RMessageView *)messageView;

- (void)messageViewDidPresent:(RMessageView *)messageView;

- (void)messageViewDidDismiss:(RMessageView *)messageView;

- (CGFloat)customVerticalOffsetForMessageView:(RMessageView *)messageView;

- (void)windowRemovedForEndlessDurationMessageView:(RMessageView *)messageView;

- (void)didSwipeToDismissMessageView:(RMessageView *)messageView;

- (void)didTapMessageView:(RMessageView *)messageView;

@end
