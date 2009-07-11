#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIViewController (TTCategory)

/**
 * The URL that was used to load this controller through TTNavigator.
 */
@property(nonatomic,copy) NSString* navigatorURL;

/**
 * A temporary holding place for persisted view state waiting to be restored.
 *
 * While restoring controllers, TTURLMap will assign this the dictionary created by persistView.
 * Ultimately, this state is bound for the restoreView call, but it is up to subclasses to
 * call restoreView at the appropriate time -- usually after the view has been created.
 *
 * After you've restored the state, you should set frozenState to nil.
 */
@property(nonatomic,retain) NSDictionary* frozenState;

/**
 * The container that contains this view controller.
 *
 * This is just like parentViewController, except that it is not readonly.  This offers
 * other UIViewControllers to assign themselves as the container of this URL.  TTNavigator
 * makes use of this property to manage the hierarchy of controllers.
 */
@property(nonatomic,retain) UIViewController* containingViewController;

/**
 * The view controller that comes before this one in a navigation controller's history.
 */
- (UIViewController*)previousViewController;

/**
 * The view controller that comes after this one in a navigation controller's history.
 */
- (UIViewController*)nextViewController;

/**
 * The visible child view controller of this view controller, if it is a container.
 */
- (UIViewController*)childViewController;

/**
 * Displays a controller inside this controller.
 *
 * TTURLMap uses this to display newly created controllers.  The default does nothing --
 * UIViewController categories and subclasses should implement to display the controller
 * in a manner specific to them.  
 */
- (void)presentController:(UIViewController*)controller animated:(BOOL)animated;

/**
 * Brings a controller that is a child of this controller to the front.
 *
 * TTURLMap uses this to display controllers that exist already, but may not be visible.
 * The default does nothing -- UIViewController categories and subclasses should implement
 * to display the controller in a manner specific to them.  
 */
- (void)bringControllerToFront:(UIViewController*)controller animated:(BOOL)animated;

/**
 * Determines whether a controller is primarily a container of other controllers.
 */
- (BOOL)isContainerController;

- (void)persistNavigationPath:(NSMutableArray*)path;

- (void)persistView:(NSMutableDictionary*)state;

- (void)restoreView:(NSDictionary*)state;

/**
 * Shows a UIAlertView with a message and title.
 *
 * @delegate A UIAlertView delegate
 */ 
- (void)alert:(NSString*)message title:(NSString*)title delegate:(id)delegate;

/**
 * Shows a UIAlertView with a message.
 */ 
- (void)alert:(NSString*)message;

/**
 * Shows a UIAlertView with an error message.
 */ 
- (void)alertError:(NSString*)message;

/**
 * Shows or hides the navigation and status bars.
 */
- (void)showBars:(BOOL)show animated:(BOOL)animated;

@end
