//
//  RMessageView.h
//  RMessage
//
//  Created by Adonis Peralta on 12/7/15.
//  Copyright © 2015 Adonis Peralta. All rights reserved.
//

#import "RMessage.h"
#import "RMessageViewProtocol.h"

@interface RMessageView : UIView

/** The displayed title of this message */
@property (nonatomic, readonly) NSAttributedString *title;

/** The displayed subtitle of this message */
@property (nonatomic, readonly) NSAttributedString *subtitle;

/** The view controller this message is displayed in */
@property (nonatomic, readonly) UIViewController *viewController;

/** The duration of the displayed message. If it is 0.0, it will automatically be calculated */
@property (nonatomic, assign) CGFloat duration;

/** The position of the message (top or bottom) */
@property (nonatomic, assign) RMessagePosition messagePosition;

/** The message type that the RMessageView was initialized with */
@property (nonatomic, assign, readonly) RMessageType messageType;

/** The customTypeName if any the RMessageView was initialized with */
@property (nonatomic, copy, readonly) NSString *customTypeName;

/** Is the message currently in the process of presenting, but not yet displayed? */
@property (nonatomic, assign) BOOL isPresenting;

/** Is the message currently fully displayed? Is set as soon as the message is really fully visible */
@property (nonatomic, assign) BOOL messageIsFullyDisplayed;

/** Customize RMessage properties via use of delegate customizeMessageView function */
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, assign) NSTextAlignment titleAlignment;
@property (nonatomic, strong) UIColor *titleTextColor;
@property (nonatomic, strong) UIFont *subtitleFont;
@property (nonatomic, assign) NSTextAlignment subtitleAlignment;
@property (nonatomic, strong) UIColor *subtitleTextColor;

/** The opacity of the message view. When customizing RMessage always set this value to the desired opacity instead of
 the alpha property. Internally the alpha property is changed during animations; this property allows RMessage to
 always know the final alpha value
 */
@property (nonatomic, assign) CGFloat messageOpacity;

/** Set the margin between all elements, by default 10.f */
@property (nonatomic, assign) CGFloat interElementMargin;

/**
 Inits the message view. Do not call this from outside this library.
 @param delegate The delegate of the message view
 @param title The title of the message view
 @param subtitle The subtitle of the message view (optional)
 @param messageType The type of message view
 @param customTypeName The string identifier/key for the custom style to use from specified custom
 @param duration The duration this notification should be displayed (optional)
 @param viewController The view controller this message should be displayed in
 @param position The position of the message on the screen
 @param dismissingEnabled Should this message be dismissed when the user taps/swipes it?
 @param leftView The view to position on the left of the title and subtitle labels
 @param rightView The view to position on the right of the title and subtitle labels
 @param backgroundView The view to position as the background view of the message
 @param tapBlock The block that should be executed when the user taps on the message
 @param dismissalBlock The block that should be executed, after the message is dismissed
 @param completionBlock The block that should be executed after the message finishes presenting
 */
- (instancetype)initWithDelegate:(id<RMessageViewProtocol>)delegate
                           title:(NSAttributedString *)title
                        subtitle:(NSAttributedString *)subtitle
                            type:(RMessageType)messageType
                  customTypeName:(NSString *)customTypeName
                        duration:(CGFloat)duration
                inViewController:(UIViewController *)viewController
                      atPosition:(RMessagePosition)position
            canBeDismissedByUser:(BOOL)dismissingEnabled
                        leftView:(UIView *)leftView
                       rightView:(UIView *)rightView
                  backgroundView:(UIView *)backgroundView
                       tapAction:(void (^)(void))tapBlock
                       dismissal:(void (^)(void))dismissalBlock
                      completion:(void (^)(void))completionBlock;

/** Use this method to load a custom design file on top of the base design file. Can be called
 multiple times to add designs from multiple files */
+ (void)addDesignsFromFileWithName:(NSString *)filename inBundle:(NSBundle *)bundle;

/** Execute the message view tap action if set */
- (void)executeMessageViewTapAction;

/** Present the message view */
- (void)present;

/** Dismiss the view with a completion block */
- (void)dismissWithCompletion:(void (^)(void))completionBlock;

#pragma mark Customization functions

/** Set the vertical spacing/margin between the title and subtitle labels */
- (void)setTitleSubtitleLabelsVerticalSpacing:(CGFloat)spacing;

/** Set the horizontal leading margin between the title/subtitle labels and the container or leftView (if not nil)
 */
- (void)setTitleSubtitleLeadingMargin:(CGFloat)margin;

/** Set the horizontal trailing margin between the title/subtitle labels and the container or rightView (if not nil) */
- (void)setTitleSubtitleTrailingMargin:(CGFloat)margin;

/** Set the vertical margin between the message top and the superview top */
- (void)setVerticalSpacingToSuperViewTop:(CGFloat)spacing;

/** Set the vertical margin between the message bottom and the superview bottom */
- (void)setVerticalSpacingToSuperViewBottom:(CGFloat)spacing;

- (void)interfaceDidRotate;

@end
