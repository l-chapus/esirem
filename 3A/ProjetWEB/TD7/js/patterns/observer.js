export class Observer
{
    /**
     * Notification function. Has to be overrided
     */
    notify()
    {
        throw new Error("You have to define this function !");
    }
}